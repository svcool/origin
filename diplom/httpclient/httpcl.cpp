#include "httpcl.h"
#include "root_certificates.hpp"

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <cstdlib>
#include <iostream>


namespace beast = boost::beast; // from <boost/beast.hpp>
namespace http = beast::http;   // from <boost/beast/http.hpp>
namespace net = boost::asio;    // from <boost/asio.hpp>
namespace ssl = net::ssl;       // from <boost/asio/ssl.hpp>
using tcp = net::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

// Реализация функции perform_request
std::string perform_request(const std::string& host, const std::string& port, const std::string& target, int version)
{
    try
    {
        // The io_context is required for all I/O
        net::io_context ioc;
        beast::error_code ec;
        // The SSL context is required, and holds certificates
        ssl::context ctx(ssl::context::tlsv12_client);

        // This holds the root certificate used for verification
        load_root_certificates(ctx);

        // Verify the remote server's certificate
        ctx.set_verify_mode(ssl::verify_peer);

        // These objects perform our I/O
        tcp::resolver resolver(ioc);
        beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);

        // Set SNI Hostname (many hosts need this to handshake successfully)
        if (!SSL_set_tlsext_host_name(stream.native_handle(), host.c_str()))
        {
            beast::error_code ec{ static_cast<int>(::ERR_get_error()), net::error::get_ssl_category() };
            throw beast::system_error{ ec };
        }

        // Look up the domain name
        auto const results = resolver.resolve(host, port);

        // Make the connection on the IP address we get from a lookup
        beast::get_lowest_layer(stream).connect(results);

        // Perform the SSL handshake if it's HTTPS (port 443)
        if (port == "443") {
            stream.handshake(ssl::stream_base::client);
        }

        // Set up an HTTP GET request message
        http::request<http::string_body> req{ http::verb::get, target, version };
        req.set(http::field::host, host);
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

        // Send the HTTP request to the remote host
        http::write(stream, req);
     /*   if (ec) {
            throw HttpClientError("Ошибка при отправке запроса: " + ec.message());
        }*/
        // This buffer is used for reading and must be persisted
        beast::flat_buffer buffer;

        // Declare a container to hold the response
        http::response<http::dynamic_body> res;

        // Receive the HTTP response
        http::read(stream, buffer, res, ec);
        //if (ec) {
        //    throw HttpClientError("Ошибка при чтении ответа: " + ec.message());
        //}
        //// Write the message to standard out
        //std::cout << "Страница прочитана, парсинг..." << std::endl;

        // Write the message to standard out
        std::cout << res << std::endl;
        stream.shutdown(ec);

        if (ec == net::error::eof)
        {
            ec = {};
        }
        if (ec)
            throw beast::system_error{ ec };

        std::string response_body = boost::beast::buffers_to_string(res.body().data());//преобразуем в string
        return response_body;
    }
    catch (const beast::system_error& e)
    {
        std::cerr << "SSL/TCP Error: " << e.what() << std::endl;
        throw;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        throw;
    }
}

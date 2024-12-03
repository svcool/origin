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
#include <string>

namespace beast = boost::beast; // from <boost/beast.hpp>
namespace http = beast::http;   // from <boost/beast/http.hpp>
namespace net = boost::asio;    // from <boost/asio.hpp>
namespace ssl = net::ssl;       // from <boost/asio/ssl.hpp>
using tcp = net::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

// Performs an HTTP GET and prints the response
void perform_request(const std::string& host, const std::string& port, const std::string& target, int version)
{
    try
    {
        // The io_context is required for all I/O
        net::io_context ioc;

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

        // This buffer is used for reading and must be persisted
        beast::flat_buffer buffer;

        // Declare a container to hold the response
        http::response<http::dynamic_body> res;

        // Receive the HTTP response
        http::read(stream, buffer, res);

        // Write the message to standard out
        std::cout << res << std::endl;

        // Gracefully close the stream
        beast::error_code ec;
        stream.shutdown(ec);
        if (ec == net::error::eof)
        {
            // Rationale:
            // http://stackoverflow.com/questions/25587403/boost-asio-ssl-async-shutdown-always-finishes-with-an-error
            ec = {};
        }
        if (ec)
            throw beast::system_error{ ec };

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

// Main function with retry logic for different ports (first HTTP, then HTTPS, reverse on failure)
int main(int argc, char** argv)
{
    try
    {
        if (argc != 4 && argc != 5)
        {
            std::cerr <<
                "Usage: http-client-sync-ssl <host> <port> <target> [<HTTP version: 1.0 or 1.1(default)>]\n" <<
                "Example:\n" <<
                "    http-client-sync-ssl www.example.com 443 /\n" <<
                "    http-client-sync-ssl www.example.com 443 / 1.0\n";
            return EXIT_FAILURE;
        }

        auto const host = argv[1];
        auto const target = argv[3];
        int version = argc == 5 && !std::strcmp("1.0", argv[4]) ? 10 : 11;

        // First attempt with HTTP (port 80)
        try
        {
            std::cout << "Attempting to connect to " << host << " via HTTP (port 80)...\n";
            perform_request(host, "80", target, version);
            return EXIT_SUCCESS; // If successful, exit early
        }
        catch (const std::exception& e)
        {
            std::cerr << "Failed with HTTP (port 80), trying HTTPS (port 443)...\n";
        }

        // If HTTP failed, try HTTPS (port 443)
        try
        {
            std::cout << "Attempting to connect to " << host << " via HTTPS (port 443)...\n";
            perform_request(host, "443", target, version);
            return EXIT_SUCCESS; // If successful, exit early
        }
        catch (const std::exception& e)
        {
            std::cerr << "Failed with HTTPS (port 443), trying HTTP (port 80)...\n";
        }

        // If HTTPS failed, try HTTP again (port 80)
        try
        {
            std::cout << "Attempting to connect to " << host << " via HTTP (port 80) again...\n";
            perform_request(host, "80", target, version);
            return EXIT_SUCCESS; // If successful, exit early
        }
        catch (const std::exception& e)
        {
            std::cerr << "Failed with HTTP (port 80) again, exiting.\n";
            throw std::runtime_error("Failed to connect to the server on both HTTP and HTTPS ports.");
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}

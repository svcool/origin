#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

namespace beast = boost::beast;     // from <boost/beast.hpp>
namespace http = beast::http;       // from <boost/beast/http.hpp>
namespace net = boost::asio;        // from <boost/asio.hpp>
using tcp = net::ip::tcp;           // from <boost/asio/ip/tcp.hpp>

//************chcp 65001**************diplom otzovik.com 80 /reviews/otus-onlayn-obrazovanie/gallery/
// Performs an HTTP GET and prints the response
int main(int argc, char** argv)
{
    try
    {
        // Check command line arguments.
        if (argc != 4 && argc != 5)
        {
            std::cerr <<
                "Usage: http-client-sync <host> <port> <target> [<HTTP version: 1.0 or 1.1(default)>]\n" <<
                "Example:\n" <<
                "    http-client-sync www.example.com 80 /\n" <<
                "    http-client-sync www.example.com 80 / 1.0\n";
            return EXIT_FAILURE;
        }
        auto const host = argv[1];
        auto const port = argv[2];
        auto const target = argv[3];
        int version = argc == 5 && !std::strcmp("1.0", argv[4]) ? 10 : 11;

        // The io_context is required for all I/O
        net::io_context ioc;

        // These objects perform our I/O
        tcp::resolver resolver(ioc);
        beast::tcp_stream stream(ioc);

        // Look up the domain name
        auto const results = resolver.resolve(host, port);

        // Make the connection on the IP address we get from a lookup
        stream.connect(results);

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

        // Gracefully close the socket
        beast::error_code ec;
        stream.socket().shutdown(tcp::socket::shutdown_both, ec);

        // not_connected happens sometimes
        // so don't bother reporting it.
        //
        if (ec && ec != beast::errc::not_connected)
            throw beast::system_error{ ec };

        // If we get here then the connection is closed gracefully
    }
    catch (std::exception const& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

//#include <boost/beast/core.hpp>
//#include <boost/beast/http.hpp>
//#include <boost/asio/connect.hpp>
//#include <boost/asio/ip/tcp.hpp>
//#include <iostream>
//
//namespace beast = boost::beast;
//namespace http = beast::http;
//namespace net = boost::asio;
//using tcp = net::ip::tcp;
//
//int main() {
//    try {
//        // Создаем I/O контекст
//        net::io_context ioc;
//
//        // Resolver для получения IP-адреса
//        tcp::resolver resolver(ioc);
//        auto const results = resolver.resolve("example.com", "80");
//
//        // Создаем сокет и соединяем его
//        beast::tcp_stream stream(ioc);
//        net::connect(stream.socket(), results.begin(), results.end());
//
//        // Создаем HTTP-запрос
//        http::request<http::string_body> req{ http::verb::get, "/", 11 };
//        req.set(http::field::host, "example.com");
//        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
//
//        // Отправляем запрос
//        http::write(stream, req);
//
//        // Получаем ответ
//        beast::flat_buffer buffer;
//        http::response<http::string_body> res;
//        http::read(stream, buffer, res);
//
//        // Печатаем HTML-контент
//        std::cout << res.body() << std::endl;
//
//        // Закрываем сокет
//        beast::error_code ec;
//        stream.socket().shutdown(tcp::socket::shutdown_both, ec);
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Ошибка: " << e.what() << std::endl;
//    }
//
//    return 0;
//}
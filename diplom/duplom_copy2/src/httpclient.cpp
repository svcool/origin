#include "httpclient.h"

//***********************************************************************************************
std::string http_get(const std::string& host, const std::string& port, const std::string& target, int version) {
    
    std::cout << host << " " << port << " " << target;
    // The io_context is required for all I/O
    net::io_context ioc;
    beast::error_code ec;
    // These objects perform our I/O
    tcp::resolver resolver(ioc);
    beast::tcp_stream stream(ioc);

    // Look up the domain name
    auto const results = resolver.resolve(host, port);

    // Make the connection on the IP address we get from a lookup
    stream.connect(results, ec);
    if (ec) {
     throw HttpClientError("Ошибка соединения: " + ec.message());
     }
    // Set up an HTTP GET request message
    http::request<http::string_body> req{ http::verb::get, target, version };
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    // Send the HTTP request to the remote host
    http::write(stream, req, ec);
    if (ec) {
     throw HttpClientError("Ошибка при отправке запроса: " + ec.message());
     }
    // This buffer is used for reading and must be persisted
    beast::flat_buffer buffer;

    // Declare a container to hold the response
    http::response<http::dynamic_body> res;

    // Receive the HTTP response
    http::read(stream, buffer, res, ec);
    if (ec) {
     throw HttpClientError("Ошибка при чтении ответа: " + ec.message());
     }
    // Write the message to standard out
    std::cout << "Страница прочитана, парсинг..." << std::endl;

    // Gracefully close the socket
     stream.socket().shutdown(tcp::socket::shutdown_both, ec);

    // not_connected happens sometimes, so don't bother reporting it.
    if (ec && ec != beast::errc::not_connected)
        throw HttpClientError("Ошибка при отправке запроса: " + ec.message());

    stream.socket().shutdown(tcp::socket::shutdown_both, ec);

    std::string response_body = boost::beast::buffers_to_string(res.body().data());//преобразуем в string

    return response_body;
}
//***********************************************************************************************
#include "httpclient.h"
std::string httpGet(const std::string& host, const std::string& port, const std::string& target, int version) {
    // Основная попытка
    std::string result = HttpGetInternal(host, port, target, version);
    if (!result.empty()) {
        return result;
    }

    // Резервная попытка с другим портом
    std::string fallback_port = (port == "443") ? "80" : "443";
    return HttpGetInternal(host, fallback_port, target, version);
}

std::string HttpGetInternal(const std::string& host, const std::string& port, const std::string& target, int version) {
    try {
        return httpClientGet(host, port, target, version);
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка соединения через порт " << port << ": " << e.what() << std::endl;
        return "";
    }
}

std::string httpClientGet(const std::string& host, const std::string& port, const std::string& target, int version) {
    
    std::cout << host << " " << port << " " << target;
    net::io_context ioc;
    ssl::context ctx(ssl::context::tlsv12_client);
    load_root_certificates(ctx);
    ctx.set_verify_mode(ssl::verify_peer);

    beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);

    if (port == "443" && !SSL_set_tlsext_host_name(stream.native_handle(), host.c_str())) {
        beast::error_code ec{ static_cast<int>(::ERR_get_error()), net::error::get_ssl_category() };
        throw beast::system_error{ ec };
    }

    tcp::resolver resolver(ioc);
    auto const results = resolver.resolve(host, port);

    // Установка таймаута на подключение
    beast::get_lowest_layer(stream).expires_after(std::chrono::seconds(10));
    beast::get_lowest_layer(stream).connect(results);

    // SSL Handshake для HTTPS
    if (port == "443") {
        stream.handshake(ssl::stream_base::client);
    }

    http::request<http::string_body> req{ http::verb::get, target, version };
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    // Таймаут на запись
    beast::get_lowest_layer(stream).expires_after(std::chrono::seconds(10));
    http::write(stream, req);

    beast::flat_buffer buffer;
    http::response<http::dynamic_body> res;

    // Таймаут на чтение
    beast::get_lowest_layer(stream).expires_after(std::chrono::seconds(10));
    http::read(stream, buffer, res);

    if (port == "443") {
        beast::error_code ec;
        stream.shutdown(ec);
        if (ec == net::error::eof) {
            ec = {}; 
        }
        if (ec) {
            throw beast::system_error{ ec };
        }
    }

    return boost::beast::buffers_to_string(res.body().data());
}











////***********************************************************************************************
//std::string http_get(const std::string& host, const std::string& port, const std::string& target, int version) {
//    
//    std::cout << host << " " << port << " " << target;
//    // The io_context is required for all I/O
//    net::io_context ioc;
//    beast::error_code ec;
//    // These objects perform our I/O
//    tcp::resolver resolver(ioc);
//    beast::tcp_stream stream(ioc);
//
//    // Look up the domain name
//    auto const results = resolver.resolve(host, port);
//
//    // Make the connection on the IP address we get from a lookup
//    stream.connect(results, ec);
//    if (ec) {
//     throw HttpClientError("Ошибка соединения: " + ec.message());
//     }
//    // Set up an HTTP GET request message
//    http::request<http::string_body> req{ http::verb::get, target, version };
//    req.set(http::field::host, host);
//    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
//
//    // Send the HTTP request to the remote host
//    http::write(stream, req, ec);
//    if (ec) {
//     throw HttpClientError("Ошибка при отправке запроса: " + ec.message());
//     }
//    // This buffer is used for reading and must be persisted
//    beast::flat_buffer buffer;
//
//    // Declare a container to hold the response
//    http::response<http::dynamic_body> res;
//
//    // Receive the HTTP response
//    http::read(stream, buffer, res, ec);
//    if (ec) {
//     throw HttpClientError("Ошибка при чтении ответа: " + ec.message());
//     }
//    // Write the message to standard out
//    std::cout << "Страница прочитана, парсинг..." << std::endl;
//
//    // Gracefully close the socket
//     stream.socket().shutdown(tcp::socket::shutdown_both, ec);
//
//    // not_connected happens sometimes, so don't bother reporting it.
//    if (ec && ec != beast::errc::not_connected)
//        throw HttpClientError("Ошибка при отправке запроса: " + ec.message());
//
//    stream.socket().shutdown(tcp::socket::shutdown_both, ec);
//
//    std::string response_body = boost::beast::buffers_to_string(res.body().data());//преобразуем в string
//
//    return response_body;
//}
////***********************************************************************************************

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <globals.h>
#include <regex>
#include <iomanip>
#include <random>

namespace beast = boost::beast;     // from <boost/beast.hpp>
namespace http = beast::http;       // from <boost/beast/http.hpp>
namespace net = boost::asio;        // from <boost/asio.hpp>
using tcp = net::ip::tcp;           // from <boost/asio/ip/tcp.hpp>

// Функция для выполнения HTTP GET запроса
http::response<http::dynamic_body> http_get(const std::string& host, const std::string& port, const std::string& target, int version) {
    // Создаем I/O контекст
    net::io_context ioc;
    tcp::resolver resolver(ioc);
    beast::tcp_stream stream(ioc);
    // Замена префикса на пустую строку
    std::string url = std::regex_replace(host, std::regex(R"(^https?://)"), "");
    // Разрешаем адрес
    auto const results = resolver.resolve(url, port);

    // Пытаемся установить соединение
    beast::error_code ec;
    stream.connect(results, ec);
    if (ec) {
        throw HttpClientError("Ошибка соединения: " + ec.message());
    }

    // Настраиваем HTTP GET запрос
    http::request<http::string_body> req{ http::verb::get, "/" + target, version };
    req.set(http::field::host, url);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    // Отправляем запрос
    http::write(stream, req, ec);
    if (ec) {
        throw HttpClientError("Ошибка при отправке запроса: " + ec.message());
    }

    // Получаем ответ
    beast::flat_buffer buffer;
    http::response<http::dynamic_body> res;
    http::read(stream, buffer, res, ec);
    if (ec) {
        throw HttpClientError("Ошибка при чтении ответа: " + ec.message());
    }

    // Проверяем статус ответа
    if (res.result() != http::status::ok) {
        throw HttpClientError("Ошибка: " + std::to_string(res.result_int()) + " " + std::string(res.reason().data(), res.reason().size()));
    }

    return move(res);
}
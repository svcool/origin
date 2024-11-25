#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>
#include <cstdlib>
#include <globals.h>

#include <fstream>
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <ctime>

namespace beast = boost::beast;     // from <boost/beast.hpp>
namespace http = beast::http;       // from <boost/beast/http.hpp>
namespace net = boost::asio;        // from <boost/asio.hpp>
using tcp = net::ip::tcp;           // from <boost/asio/ip/tcp.hpp>

// Функция для генерации уникального имени файла
std::string generate_temp_filename() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::ostringstream oss;
    oss << "temp_" << std::put_time(std::localtime(&now_c), "%Y%m%d_%H%M%S") << "_" << rand() % 10000 << ".txt";
    return oss.str();
}

// Функция для выполнения HTTP GET запроса
std::string http_get(const std::string& host, const std::string& port, const std::string& target, int version) {
    // Создаем I/O контекст
    net::io_context ioc;
    tcp::resolver resolver(ioc);
    beast::tcp_stream stream(ioc);

    // Разрешаем адрес
    auto const results = resolver.resolve(host, port);

    // Пытаемся установить соединение
    beast::error_code ec;
    stream.connect(results, ec);
    if (ec) {
        throw HttpClientError("Ошибка соединения: " + ec.message());
    }

    // Настраиваем HTTP GET запрос
    http::request<http::string_body> req{ http::verb::get, "/" + target, version};
    req.set(http::field::host, host);
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

    // Сохраняем ответ во временный файл
    std::string temp_filename = generate_temp_filename();
    std::ofstream ofs(temp_filename);
    if (!ofs) {
        throw HttpClientError("Не удалось создать временный файл: " + temp_filename);
    }
    ofs << res << std::endl;
    ofs.close();

    std::cout << "Ответ сохранен в файл: " << temp_filename << std::endl;

    return temp_filename; // Возвращаем имя временного файла
}

int main() {
    // Установка кодировки консоли на UTF-8
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    try {
        // Параметры запроса
        std::string host = "otzovik.com";
        std::string port = "80";
        std::string target = "review_14198894.html";
        int version = 11;

        // Выполняем GET запрос и получаем имя временного файла
        std::string temp_file = http_get(host, port, target, version);
        std::cout << "Имя временного файла: " << temp_file << std::endl;
    }
    catch (const HttpClientError& e) {
        std::cerr << "HTTP ошибка: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка:" << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

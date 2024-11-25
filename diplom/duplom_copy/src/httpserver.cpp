//
// Copyright (c) 2017 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//

//------------------------------------------------------------------------------
//
// Example: HTTP server, small
//
//------------------------------------------------------------------------------

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>
#include <ctime>
#include <globals.h>

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

namespace my_program_state
{
    std::size_t
    request_count()
    {
        static std::size_t count = 0;
        return ++count;
    }

    std::time_t
    now()
    {
        return std::time(0);
    }
}

class http_connection : public std::enable_shared_from_this<http_connection>
{
public:
    http_connection(tcp::socket socket)
        : socket_(std::move(socket))
    {
    }

    // Initiate the asynchronous operations associated with the connection.
    void
    start()
    {
        read_request();
        check_deadline();
    }

private:
    // The socket for the currently connected client.
    tcp::socket socket_;

    // The buffer for performing reads.
    beast::flat_buffer buffer_{8192};

    // The request message.
    http::request<http::dynamic_body> request_;

    // The response message.
    http::response<http::dynamic_body> response_;

    // The timer for putting a deadline on connection processing.
    net::steady_timer deadline_{
        socket_.get_executor(), std::chrono::seconds(60)};

    // Asynchronously receive a complete request message.
    void
    read_request()
    {
        auto self = shared_from_this();

        http::async_read(
            socket_,
            buffer_,
            request_,
            [self](beast::error_code ec,
                std::size_t bytes_transferred)
            {
                boost::ignore_unused(bytes_transferred);
                if(!ec)
                    self->process_request();
            });
    }

    // Determine what needs to be done with the request message.
    void
    process_request()
    {
        response_.version(request_.version());
        response_.keep_alive(false);

        switch(request_.method())
        {
        case http::verb::get:
            response_.result(http::status::ok);
            response_.set(http::field::server, "Beast");
            create_response();
            break;

        default:
            // We return responses indicating an error if
            // we do not recognize the request method.
            response_.result(http::status::bad_request);
            response_.set(http::field::content_type, "text/plain");
            beast::ostream(response_.body())
                << "Invalid request-method '"
                << std::string(request_.method_string())
                << "'";
            break;
        }

        write_response();
    }

    // Функция для выполнения поиска
    std::vector<SearchResult> perform_search(const std::string& query) {
        std::vector<SearchResult> results;

        // Здесь должна быть логика поиска по базе данных
        // Например, добавим несколько примеров результатов
        results.push_back({ "https://netology.ru/profile/program/cpp-14/schedule/all", 5 }); // 5 упоминаний
        results.push_back({ "https://www.cyberforum.ru/boost-cpp/thread2383592.html", 3 }); // 3 упоминания
        results.push_back({ "https://www.boost.org/doc/libs/1_73_0/boost/property_tree/ptree.hpp", 7 }); // 7 упоминаний
        results.push_back({ "http://forum.oszone.net/thread-251593.html", 7 }); // 7 упоминаний
        // Сортируем результаты по частоте упоминаний в порядке убывания
        std::sort(results.begin(), results.end(), [](const SearchResult& a, const SearchResult& b) {
            return a.frequency > b.frequency;
            });

        return results;
    }

    void create_response() {
        // Устанавливаем заголовок CORS
        response_.set(http::field::access_control_allow_origin, "*");

        if (request_.target().starts_with("/search")) {
            std::string query = request_.target().substr(7); // Извлечение параметра query

            // Выполнение поиска
            std::vector<SearchResult> results = perform_search(query);

            // Формируем ответ в формате JSON
            response_.set(http::field::content_type, "application/json");
            beast::ostream(response_.body()) << "[";
            for (size_t i = 0; i < results.size(); ++i) {
                beast::ostream(response_.body()) << "{\"url\": \"" << results[i].url << "\", \"frequency\": " << results[i].frequency << "}";
                if (i < results.size() - 1) {
                    beast::ostream(response_.body()) << ",";
                }
            }
            beast::ostream(response_.body()) << "]";
        }
        else if (request_.target() == "/count") {
            response_.set(http::field::content_type, "text/html; charset=utf-8");
            beast::ostream(response_.body())
                << "<html>\n"
                << "<head><title>Количество запросовfgdfgdfsgs</title></head>\n"
                << "<body>\n"
                << "<h1>Количество запросов</h1>\n"
                << "<p>Всего было " << my_program_state::request_count() << " запросов.</p>\n"
                << "</body>\n"
                << "</html>\n";
        }
        else if (request_.target() == "/time") {
            response_.set(http::field::content_type, "text/html; charset=utf-8");
            std::time_t seconds = my_program_state::now();
            std::tm* ptm = std::localtime(&seconds);
            char timeinfo[30];
            std::strftime(timeinfo, sizeof(timeinfo), "%Y-%m-%d %H:%M:%S", ptm);

            beast::ostream(response_.body())
                << "<html>\n"
                << "<head><title>lkjl  Текущее</title></head>\n"
                << "<body>\n"
                << "<h1>Текущее время</h1>\n"
                << "<p>Текущее время: " << timeinfo
                << "</p>\n"
                << "</body>\n"
                << "</html>\n";
        }
        else {
            response_.result(http::status::not_found);
            response_.set(http::field::content_type, "text/plain");
            beast::ostream(response_.body()) << "Файл не найден\r\n";
        }
    }

 
    // Asynchronously transmit the response message.
    void
    write_response()
    {
        auto self = shared_from_this();

        response_.content_length(response_.body().size());

        http::async_write(
            socket_,
            response_,
            [self](beast::error_code ec, std::size_t)
            {
                self->socket_.shutdown(tcp::socket::shutdown_send, ec);
                self->deadline_.cancel();
            });
    }

    // Check whether we have spent enough time on this connection.
    void
    check_deadline()
    {
        auto self = shared_from_this();

        deadline_.async_wait(
            [self](beast::error_code ec)
            {
                if(!ec)
                {
                    // Close socket to cancel any outstanding operation.
                    self->socket_.close(ec);
                }
            });
    }
};

// "Loop" forever accepting new connections.
void
http_server(tcp::acceptor& acceptor, tcp::socket& socket)
{
  acceptor.async_accept(socket,
      [&](beast::error_code ec)
      {
          if(!ec)
              std::make_shared<http_connection>(std::move(socket))->start();
          http_server(acceptor, socket);
      });
}

int
main(int argc, char* argv[])
{

    std::vector<SearchResult> results;

    SearchResult result;
    result.url = "https://gpt-chatbot.ru/poisk-v-internete-onlajn-s-pomoshhju-iskusstvennogo-intellekta";
    result.frequency = 5;
    results.push_back(result);
    result.url = "https://netology.ru/profile/program/fcpp-14/lessons/444790/lesson_items/2402661";
    result.frequency = 3;
    results.push_back(result);
    result.url = "https://stackoverflow.com/questions/3897839/how-to-link-c-program-with-boost-using-cmake";
    result.frequency = 8;
    results.push_back(result);

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    //curl http://localhost:80/time //количество запросов
    //curl http ://localhost:8080/count // время
    try
    {

        
        // Параметры сервера: адрес и порт
        auto const address = net::ip::make_address("0.0.0.0"); // Принимаем на всех интерфейсах
        unsigned short port = 8080; // Порт 80
        net::io_context ioc{ 1 };

        tcp::acceptor acceptor{ ioc, {address, port} };
        tcp::socket socket{ ioc };

        // Запуск HTTP сервера в отдельном потоке
        std::thread server_thread([&]() {
            http_server(acceptor, socket);
            ioc.run();
            });

        // Задержка перед открытием браузера
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Открываем браузер с нужной страницей
        std::string url = "http://localhost:8080/time";
        //std::string command = "xdg-open " + url; // Для Linux
        std::string command = "start " + url; // Для Windows
        // std::string command = "open " + url; // Для MacOS

        system(command.c_str());

        // Ожидаем завершения потока сервера

        server_thread.join();


    }
    catch(std::exception const& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}

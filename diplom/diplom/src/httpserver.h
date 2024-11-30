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
#include <set>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>
#include <ctime>
#include <regex>

#include <Windows.h>
#include <except.h>
#include <ctime>
#include <chrono>


#include <bd.h>

struct SearchResult {
    std::string url;
    int frequency;
};

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
    http_connection(tcp::socket socket, manage_db& dbq)
        : socket_(std::move(socket)), dbq(dbq)
    {
       // this->dbq = dbq;
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
    manage_db& dbq;
       // The buffer for performing reads.
    beast::flat_buffer buffer_{ 8192 };

    // The request message.
    http::request<http::dynamic_body> request_;

    // The response message.
    http::response<http::dynamic_body> response_;

    // The timer for putting a deadline on connection processing.
    net::steady_timer deadline_{
        socket_.get_executor(), std::chrono::seconds(60) };

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
                if (!ec)
                    self->process_request();
            });
    }

    // Determine what needs to be done with the request message.
    void
        process_request()
    {
        response_.version(request_.version());
        response_.keep_alive(false);

        switch (request_.method())
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

    std::set<std::string> skippingWords(const std::string& query) {
        // Удаление знаков препинания и лишних пробелов
        std::string cleaned_text = std::regex_replace(query, std::regex(R"([.,!?;:'\"(){}[\]<>-]|[\n\t])"), " ");
        cleaned_text = std::regex_replace(query, std::regex(R"([\s]+)"), " ");

        // Преобразование текста в нижний регистр
        std::transform(cleaned_text.begin(), cleaned_text.end(), cleaned_text.begin(),
            [](unsigned char c) { return std::tolower(c); });

        std::set<std::string> uniqueWords;
        std::istringstream iss(cleaned_text); // Используем istringstream для разбивки текста на слова
        std::string word;

        while (iss >> word) {
            if (!word.empty()) {
                uniqueWords.insert(word); // Добавляем уникальное слово в вектор
            }
        }
        return uniqueWords;
    }

    std::vector<SelectResult> resultSearchFrequence(std::set<std::string>& cleanQuery) {
        std::vector<SelectResult> results;
        std::unordered_map<std::string, int> frequencyMap;//map c уникальым ключем

        for (const auto& clq : cleanQuery) {
            auto currentResults = dbq.selectUrlWord(clq);
            for (const auto& result : currentResults) {
                frequencyMap[result.url] += result.frequency; // Суммируем частоты для одинаковых URL
            }
        }
        // Создаем вектор SelectResult из мапы
        for (const auto& pair : frequencyMap) {
            results.emplace_back(pair.first, pair.second);
        }

        // Сортировка результатов по частоте от большего к меньшему
        std::sort(results.begin(), results.end(), [](const SelectResult& a, const SelectResult& b) {
            return a.frequency > b.frequency;
            });

        for (const auto& rsl : results) {
            std::cout << rsl.url << "--" << rsl.url << std::endl;
        }
        return results;
    }

    void create_response() {
        // Устанавливаем заголовок CORS
        response_.set(http::field::access_control_allow_origin, "*");

        if (request_.target().starts_with("/search")) {
            std::string query = request_.target().substr(14); // Извлечение параметра query
            query = std::regex_replace(query, std::regex(R"(%20)"), " ");
            std::set<std::string> cleanQuery = skippingWords(query); // подготовка запроса из предложения
            std::vector<SelectResult> results = resultSearchFrequence(cleanQuery);// Подготовка данных для вывода поиска
            
            
            // Формируем ответ в формате JSON
            response_.set(http::field::content_type, "application/json");
            beast::ostream(response_.body()) << "[";
            for (size_t i = 0; i < results.size(); ++i) {
                const auto& row = results[i];
                beast::ostream(response_.body()) << "{\"url\": \"" << row.url << "\", \"frequency\": " << row.frequency << "}";
                               
                if (i < results.size() - 1) {// Добавляем запятую, если это не последний элемент
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
                << "<h1>Количество запросов:</h1>\n"
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
                << "<h1>Текущее время:</h1>\n"
                << "<p>" << timeinfo
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
                if (!ec)
                {
                    // Close socket to cancel any outstanding operation.
                    self->socket_.close(ec);
                }
            });
    }
};

// "Loop" forever accepting new connections.
void
http_server(tcp::acceptor& acceptor, tcp::socket& socket, manage_db& dbq)
{
    acceptor.async_accept(socket,
        [&](beast::error_code ec)
        {
            if (!ec)
                std::make_shared<http_connection>(std::move(socket), dbq)->start();
            http_server(acceptor, socket, dbq);
        });
}
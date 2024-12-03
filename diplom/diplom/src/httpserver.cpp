#include "httpserver.h"
#include <bd.h>
//*****************************************************************************************
namespace my_program_state {
    std::size_t request_count() {
        static std::size_t count = 0;
        return ++count;
    }

    std::time_t now() {
        return std::time(0);
    }
}
//*****************************************************************************************
http_connection::http_connection(tcp::socket socket, manage_db& dbq)
    : socket_(std::move(socket)), dbq(dbq), deadline_(socket_.get_executor(), std::chrono::seconds(60)) {}

void http_connection::start() {
    read_request();
    check_deadline();
}
//*****************************************************************************************
void http_connection::read_request() {
    auto self = shared_from_this();
    http::async_read(socket_, buffer_, request_,
        [self](beast::error_code ec, std::size_t bytes_transferred) {
            boost::ignore_unused(bytes_transferred);
            if (!ec)
                self->process_request();
        });
}
//*****************************************************************************************
void http_connection::process_request() {
    response_.version(request_.version());
    response_.keep_alive(false);

    switch (request_.method()) {
    case http::verb::get:
        response_.result(http::status::ok);
        response_.set(http::field::server, "Beast");
        create_response();
        break;

    default:
        response_.result(http::status::bad_request);
        response_.set(http::field::content_type, "text/plain");
        beast::ostream(response_.body()) << "Invalid request-method '" << std::string(request_.method_string()) << "'";
        break;
    }

    write_response();
}
//*****************************************************************************************
std::set<std::string> http_connection::skippingWords(const std::string& query) {
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
//*****************************************************************************************
std::vector<SelectResult> http_connection::resultSearchFrequence(std::set<std::string>& cleanQuery) {
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

  /*  for (const auto& rsl : results) {
        std::cout << rsl.url << "--" << rsl.url << std::endl;
    }*/
    return results;
}
//*****************************************************************************************
void http_connection::create_response() {
    response_.set(http::field::access_control_allow_origin, "*");
    if (request_.target() == "/") {
        response_.set(http::field::content_type, "text/html; charset=utf-8");
        std::ifstream index_file("index.html");
        if (index_file) {
            beast::ostream(response_.body()) << index_file.rdbuf();
        }
        else {
            response_.result(http::status::not_found);
            response_.set(http::field::content_type, "text/plain");
            beast::ostream(response_.body()) << "Файл не найден\r\n";
        }
    }
    else if (request_.target().starts_with("/search")) {
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
            << "<head><title>Количество запросов</title></head>\n"
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
            << "<head><title>Текущее время</title></head>\n"
            << "<body>\n"
            << "<h1>Текущее время:</h1>\n"
            << "<p>" << timeinfo << "</p>\n"
            << "</body>\n"
            << "</html>\n";
    }
    else {
        response_.result(http::status::not_found);
        response_.set(http::field::content_type, "text/plain");
        beast::ostream(response_.body()) << "Файл не найден\r\n";
    }
}
//*****************************************************************************************
void http_connection::write_response() {
    auto self = shared_from_this();
    response_.content_length(response_.body().size());

    http::async_write(socket_, response_,
        [self](beast::error_code ec, std::size_t) {
            self->socket_.shutdown(tcp::socket::shutdown_send, ec);
            self->deadline_.cancel();
        });
}

void http_connection::check_deadline() {
    auto self = shared_from_this();
    deadline_.async_wait(
        [self](beast::error_code ec) {
            if (!ec) {
                self->socket_.close(ec);
            }
        });
}
//*****************************************************************************************
void http_server(tcp::acceptor& acceptor, tcp::socket& socket, manage_db& dbq) {
    acceptor.async_accept(socket,
        [&](beast::error_code ec) {
            if (!ec)
                std::make_shared<http_connection>(std::move(socket), dbq)->start();
            http_server(acceptor, socket, dbq);
        });
}
//*****************************************************************************************
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
#include <filesystem>

namespace beast = boost::beast;     // from <boost/beast.hpp>
namespace http = beast::http;       // from <boost/beast/http.hpp>
namespace net = boost::asio;        // from <boost/asio.hpp>
using tcp = net::ip::tcp;           // from <boost/asio/ip/tcp.hpp>

class TmpFile {
    std::string m_tempDir;
    std::string m_uniqueName;
    std::ofstream m_tempFile;

public:
    // Конструктор с уникальным именем файла
    TmpFile(const std::string& tempDir, const std::string& uniqueName) : m_tempDir(tempDir), m_uniqueName(uniqueName) {
        createTempFile();
    }

    // Конструктор для генерации уникального имени файла
    TmpFile(const std::string& tempDir) : m_tempDir(tempDir) {
        generateUniqueTmpFile();
        createTempFile();
    }

    // Деструктор
    ~TmpFile() {
        if (m_tempFile.is_open()) {
            m_tempFile.close();
        }
    }

    // Генерация уникального имени файла
    void generateUniqueTmpFile() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(10000, 999999);
        m_uniqueName = "tmp_" + std::to_string(dis(gen)) + ".tmp";
    }

    // Создание директории и временного файла
    void createTempFile() {
        if (!std::filesystem::exists(m_tempDir)) {
            std::filesystem::create_directory(m_tempDir);
        }
        m_uniqueName = m_tempDir + "/" + m_uniqueName; // Генерация уникального имени файла (можно улучшить)
        m_tempFile.open(m_uniqueName);
        if (!m_tempFile) {
            throw std::runtime_error("Не удалось создать временный файл.");
        }
    }

    void writeToFile(const http::response<http::dynamic_body>& response) {
        if (!m_tempFile.is_open()) {
            throw std::runtime_error("Файл не открыт для записи.");
        }

        // Записываем заголовки
        for (const auto& field : response) {
            m_tempFile << field.name() << ": " << field.value() << "\n";
        }
        m_tempFile << "\n"; // Пустая строка для отделения заголовков от тела

        // Записываем тело ответа
        m_tempFile << beast::buffers_to_string(response.body().data()) << std::endl;
    }

    // Путь к файлу
    std::string getUniqueName() const {
        return m_uniqueName;
    }

    // Запись данных в файл
    void writeToFile(const std::string& data) {
        if (m_tempFile.is_open()) {
            m_tempFile << data;
        }
        else {
            throw std::runtime_error("Файл не открыт для записи.");
        }
    }

    void closeFile() {
        m_tempFile.close();
    }


    // Чтение содержимого временного файла
    void readFromFile() const {
        std::ifstream inFile(m_uniqueName);
        if (!inFile) {
            std::cerr << "Не удалось открыть временный файл для чтения." << std::endl;
            return;
        }

        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << "Содержимое временного файла: " << line << std::endl;
        }
    }

    // Удаление файла
    void deleteFile() {
        m_tempFile.close();
        if (std::filesystem::exists(m_uniqueName)) {
            if (std::filesystem::remove(m_uniqueName)) {
                std::cout << "Файл удален: " << m_uniqueName << std::endl;
            }
            else {
                std::cerr << "Не удалось удалить файл: " << m_uniqueName << std::endl;
            }
        }
        else {
            std::cerr << "Файл не существует: " << m_uniqueName << std::endl;
        }
    }
};

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

int main55() {
    // Установка кодировки консоли на UTF-8
    setlocale(LC_ALL, "Russian");
    //system("chcp 1251");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    try {
        // Параметры запроса
        std::string host = "otzovik.com";
        std::string port = "80";
        std::string target = "review_14198894.html";
        int version = 11;

        // Выполняем GET запрос и получаем имя временного файла
        auto res = http_get(host, port, target, version);
        TmpFile tempFile("./tmp/");
        tempFile.writeToFile(res);

        std::cout << "Имя временного файла: " << tempFile.getUniqueName() << std::endl;
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

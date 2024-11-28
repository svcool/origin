#ifndef TMPFILE_H
#define TMPFILE_H

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

#include <random>
#include <filesystem>
#include <globals.h>
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
    TmpFile(const std::string& tempDir, const std::string& uniqueName);

    // Конструктор для генерации уникального имени файла
    TmpFile(const std::string& tempDir);

    // Деструктор
    ~TmpFile();

    // Генерация уникального имени файла
    void generateUniqueTmpFile();

    // Создание директории и временного файла
    void createTempFile();

    void writeToFile(const boost::beast::http::response<boost::beast::http::dynamic_body>& response);

    // Путь к файлу
    std::string getUniqueName() const;

    // Запись данных в файл
    void writeToFile(const std::string& data);

    void closeFile();

    // Чтение содержимого временного файла
    void readFromFile() const;

    // Удаление файла
    void deleteFile();
};

#endif // TMPFILE_H

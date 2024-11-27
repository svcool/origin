#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <globals.h>
#include <filesystem>
#include <iomanip>
#include <random>

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
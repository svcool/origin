#include <tempfile.h>

namespace beast = boost::beast;     // from <boost/beast.hpp>
namespace http = beast::http;       // from <boost/beast/http.hpp>
namespace net = boost::asio;        // from <boost/asio.hpp>
using tcp = net::ip::tcp;           // from <boost/asio/ip/tcp.hpp>


TmpFile::TmpFile(const std::string& tempDir, const std::string& uniqueName)
    : m_tempDir(tempDir), m_uniqueName(uniqueName) {
    createTempFile();
}

TmpFile::TmpFile(const std::string& tempDir)
    : m_tempDir(tempDir) {
    generateUniqueTmpFile();
    createTempFile();
}

TmpFile::~TmpFile() {
    if (m_tempFile.is_open()) {
        m_tempFile.close();
    }
}

void TmpFile::generateUniqueTmpFile() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(10000, 999999);
    m_uniqueName = "tmp_" + std::to_string(dis(gen)) + ".tmp";
}

// Создание директории и временного файла
void  TmpFile::createTempFile() {
    if (!std::filesystem::exists(m_tempDir)) {
        std::filesystem::create_directory(m_tempDir);
    }
    m_uniqueName = m_tempDir + "/" + m_uniqueName; // Генерация уникального имени файла (можно улучшить)
    m_tempFile.open(m_uniqueName);
    if (!m_tempFile) {
        throw std::runtime_error("Не удалось создать временный файл.");
    }
}
void TmpFile::writeToFile(const boost::beast::http::response<boost::beast::http::dynamic_body>& response) {
    if (!m_tempFile.is_open()) {
        throw std::runtime_error("Файл не открыт для записи.");
    }

    for (const auto& field : response) {
        m_tempFile << field.name() << ": " << field.value() << "\n";
    }
    m_tempFile << "\n"; // Пустая строка для отделения заголовков от тела

    m_tempFile << boost::beast::buffers_to_string(response.body().data()) << std::endl;
}

std::string TmpFile::getUniqueName() const {
    return m_uniqueName;
}

void TmpFile::writeToFile(const std::string& data) {
    if (m_tempFile.is_open()) {
        m_tempFile << data;
    }
    else {
        throw std::runtime_error("Файл не открыт для записи.");
    }
}

void TmpFile::closeFile() {
    m_tempFile.close();
}

void TmpFile::readFromFile() const {
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

void TmpFile::deleteFile() {
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


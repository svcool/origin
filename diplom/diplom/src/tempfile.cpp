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
    // ����������� � ���������� ������ �����
    TmpFile(const std::string& tempDir, const std::string& uniqueName) : m_tempDir(tempDir), m_uniqueName(uniqueName) {
        createTempFile();
    }

    // ����������� ��� ��������� ����������� ����� �����
    TmpFile(const std::string& tempDir) : m_tempDir(tempDir) {
        generateUniqueTmpFile();
        createTempFile();
    }

    // ����������
    ~TmpFile() {
        if (m_tempFile.is_open()) {
            m_tempFile.close();
        }
    }

    // ��������� ����������� ����� �����
    void generateUniqueTmpFile() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(10000, 999999);
        m_uniqueName = "tmp_" + std::to_string(dis(gen)) + ".tmp";
    }

    // �������� ���������� � ���������� �����
    void createTempFile() {
        if (!std::filesystem::exists(m_tempDir)) {
            std::filesystem::create_directory(m_tempDir);
        }
        m_uniqueName = m_tempDir + "/" + m_uniqueName; // ��������� ����������� ����� ����� (����� ��������)
        m_tempFile.open(m_uniqueName);
        if (!m_tempFile) {
            throw std::runtime_error("�� ������� ������� ��������� ����.");
        }
    }

    void writeToFile(const http::response<http::dynamic_body>& response) {
        if (!m_tempFile.is_open()) {
            throw std::runtime_error("���� �� ������ ��� ������.");
        }

        // ���������� ���������
        for (const auto& field : response) {
            m_tempFile << field.name() << ": " << field.value() << "\n";
        }
        m_tempFile << "\n"; // ������ ������ ��� ��������� ���������� �� ����

        // ���������� ���� ������
        m_tempFile << beast::buffers_to_string(response.body().data()) << std::endl;
    }

    // ���� � �����
    std::string getUniqueName() const {
        return m_uniqueName;
    }

    // ������ ������ � ����
    void writeToFile(const std::string& data) {
        if (m_tempFile.is_open()) {
            m_tempFile << data;
        }
        else {
            throw std::runtime_error("���� �� ������ ��� ������.");
        }
    }

    void closeFile() {
        m_tempFile.close();
    }


    // ������ ����������� ���������� �����
    void readFromFile() const {
        std::ifstream inFile(m_uniqueName);
        if (!inFile) {
            std::cerr << "�� ������� ������� ��������� ���� ��� ������." << std::endl;
            return;
        }

        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << "���������� ���������� �����: " << line << std::endl;
        }
    }

    // �������� �����
    void deleteFile() {
        m_tempFile.close();
        if (std::filesystem::exists(m_uniqueName)) {
            if (std::filesystem::remove(m_uniqueName)) {
                std::cout << "���� ������: " << m_uniqueName << std::endl;
            }
            else {
                std::cerr << "�� ������� ������� ����: " << m_uniqueName << std::endl;
            }
        }
        else {
            std::cerr << "���� �� ����������: " << m_uniqueName << std::endl;
        }
    }
};
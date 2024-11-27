#ifndef TMPFILE_H
#define TMPFILE_H

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <globals.h>
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
    // ����������� � ���������� ������ �����
    TmpFile(const std::string& tempDir, const std::string& uniqueName);

    // ����������� ��� ��������� ����������� ����� �����
    TmpFile(const std::string& tempDir);

    // ����������
    ~TmpFile();

    // ��������� ����������� ����� �����
    void generateUniqueTmpFile();

    // �������� ���������� � ���������� �����
    void createTempFile();

    void writeToFile(const boost::beast::http::response<boost::beast::http::dynamic_body>& response);

    // ���� � �����
    std::string getUniqueName() const;

    // ������ ������ � ����
    void writeToFile(const std::string& data);

    void closeFile();

    // ������ ����������� ���������� �����
    void readFromFile() const;

    // �������� �����
    void deleteFile();
};

#endif // TMPFILE_H

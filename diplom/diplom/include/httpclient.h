#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include "root_certificates.hpp"

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <cstdlib>
#include <iostream>
#include <except.h>

namespace beast = boost::beast; // from <boost/beast.hpp>
namespace http = beast::http;   // from <boost/beast/http.hpp>
namespace net = boost::asio;    // from <boost/asio.hpp>
namespace ssl = net::ssl;       // from <boost/asio/ssl.hpp>
using tcp = net::ip::tcp;       // from <boost/asio/ip/tcp.hpp>
// Функция для выполнения HTTPS-запроса
std::string httpGet(const std::string& host, const std::string& port, const std::string& target, int version);
std::string HttpGetInternal(const std::string & host, const std::string & port, const std::string & target, int version);
std::string httpClientGet(const std::string& host, const std::string& port, const std::string& target, int version);










//#include <boost/beast/core.hpp>
//#include <boost/beast/http.hpp>
//#include <boost/beast/version.hpp>
//#include <boost/asio/connect.hpp>
//#include <boost/asio/ip/tcp.hpp>
//#include <cstdlib>
//#include <iostream>
//#include <string>
//#include <regex>
//#include "except.h"
//
//
//namespace beast = boost::beast;     // from <boost/beast.hpp>
//namespace http = beast::http;       // from <boost/beast/http.hpp>
//namespace net = boost::asio;        // from <boost/asio.hpp>
//using tcp = net::ip::tcp;           // from <boost/asio/ip/tcp.hpp
//
//// Function to perform an HTTP GET request
//std::string http_get(const std::string& host, const std::string& port = "80", const std::string& target = "/", int version = 11);

#endif // HTTPCLIENT_H

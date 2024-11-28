#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <cstdlib>
#include <iostream>
#include <globals.h>


namespace beast = boost::beast;     // from <boost/beast.hpp>
namespace http = beast::http;       // from <boost/beast/http.hpp>
namespace net = boost::asio;        // from <boost/asio.hpp>
using tcp = net::ip::tcp;           // from <boost/asio/ip/tcp.hpp

// Function to perform an HTTP GET request
std::string http_get(const std::string& host, const std::string& port, const std::string& target, int version);

#endif // HTTPCLIENT_H

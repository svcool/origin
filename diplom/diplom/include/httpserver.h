#ifndef HTTP_CONNECTION_HPP
#define HTTP_CONNECTION_HPP

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio.hpp>
#include <boost/beast/version.hpp>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <iostream>
#include <regex>
#include <chrono>
#include <ctime>
#include <sstream>
#include <bd.h>
#include <except.h>
#include <ctime>
#include <fstream>

struct SearchResult {
	std::string url;
	int frequency;
};

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

class manage_db; // Forward declaration

class http_connection : public std::enable_shared_from_this<http_connection> {
public:
	http_connection(boost::asio::ip::tcp::socket socket, manage_db& dbq);

	void start();

private:
	boost::asio::ip::tcp::socket socket_;
	manage_db& dbq;
	boost::beast::flat_buffer buffer_{ 8192 };
	boost::beast::http::request<boost::beast::http::dynamic_body> request_;
	boost::beast::http::response<boost::beast::http::dynamic_body> response_;
	boost::asio::steady_timer deadline_;

	void read_request();
	void process_request();
	void create_response();
	void write_response();
	void check_deadline();

	std::set<std::string> skippingWords(const std::string& query);
	std::vector<SelectResult> resultSearchFrequence(std::set<std::string>& cleanQuery);
};

void http_server(boost::asio::ip::tcp::acceptor& acceptor, boost::asio::ip::tcp::socket& socket, manage_db& dbq);


#endif // HTTP_CONNECTION_HPP
#include "httpserver.h"
#include <thread>
#include <bd.h>
#include <parserini.h>
#include <windows.h> // ��� SetConsoleCP � SetConsoleOutputCP
#include <cstdlib> // ��� system()

#pragma execution_character_set("utf-8")

int main() {
	// ��������� ��������� ������� �� UTF-8
	//setlocale(LC_ALL, "Russian");
	system("chcp 65001");
	//SetConsoleCP(CP_UTF8);
	//SetConsoleOutputCP(CP_UTF8);

	try {

		boost::property_tree::ptree pt;
		const std::string filename = "settings.ini";

		// ������ ����������� ������ ini �����
		std::vector<std::string> requiredKeys = {
			"Database.host",
			"Database.port",
			"Database.dbname",
			"Database.user",
			"Database.password",
			"Spider.page",
			"Spider.recursion",
			"Crowler.address",
			"Crowler.port"
		};

		readSettings(filename, pt); // ������ �� INI �����

		checkRequiredKeys(pt, requiredKeys); // �������� ������� ���� ����������� ������

		// ������������ �������� �� ������ Database
		DbConfig dbConfig = {
		pt.get<std::string>("Database.host"), // dbHost
		pt.get<int>("Database.port"),        // port
		pt.get<std::string>("Database.dbname"), // dbName
		pt.get<std::string>("Database.user"),      // username
		pt.get<std::string>("Database.password"),   // password
		};
		std::cout << "Database Host: " << dbConfig.dbHost << std::endl;
		std::cout << "Database Port: " << dbConfig.port << std::endl;
		std::cout << "Database DB Name: " << dbConfig.dbName << std::endl;
		std::cout << "Database Username: " << dbConfig.username << std::endl;
		std::cout << "Database Username: " << dbConfig.password << std::endl;

		// �������� �� ������ Spider
		std::string page = pt.get<std::string>("Spider.page");
		int recursion = pt.get<int>("Spider.recursion");
		std::cout << "Page: " << page << std::endl;
		std::cout << "Recursion: " << recursion << std::endl;

		// �������� �� ������ Crowler
		std::string addressCrowler = pt.get<std::string>("Crowler.address");
		int portCrowler = pt.get<int>("Crowler.port");
		std::cout << "Crowler Address: " << addressCrowler << std::endl;
		std::cout << "Crowler Port: " << portCrowler << std::endl;

		//������� ���� ������
		manage_db db("dbwords", dbConfig);

		int num_threads = std::thread::hardware_concurrency();
		std::cout << "���������� ����: " << num_threads << std::endl;

		net::io_context ioc{ 1 };
		tcp::acceptor acceptor{ ioc, {net::ip::make_address(addressCrowler), static_cast<unsigned short>(portCrowler)} };
		tcp::socket socket{ ioc };
		// ������ HTTP ������� � ��������� ������
		std::thread server_thread([&]() {
			http_server(acceptor, socket, db);
			ioc.run();
			});
		//�������� ����������
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::string urlServer = "http://localhost:" + std::to_string(portCrowler);//��� Windows
		std::string command = "start " + urlServer; // ��� Windows
		system(command.c_str());

	    server_thread.join();  // ������� ���������� ������ �������
	}
	catch (const boost::property_tree::ini_parser::ini_parser_error& e) {
		std::cerr << "Error reading or writing INI file: " << e.what() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "������:" << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return 0;
}
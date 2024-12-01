#ifndef EXCEPT_H
#define EXCEPT_H

#include <exception>
#include <string>
#include <pqxx/pqxx>

class DbError : public std::exception {
	std::string message;
public:
	DbError(const std::string& message) : message{ message } {}
	const char* what() const noexcept override {
		return message.c_str();
	}
};

class ParserError : public std::runtime_error {
public:
	explicit ParserError(const std::string& message)
		: std::runtime_error("Parser error: " + message) {}
};

class HttpClientError : public std::runtime_error {
public:
	explicit HttpClientError(const std::string& message)
		: std::runtime_error("HttpClientError: " + message) {}
};

class Error : public std::runtime_error {
public:
	explicit Error(const std::string& message)
		: std::runtime_error("HttpClientError: " + message) {}
};


class DatabaseExceptionHandler {
public:
	DatabaseExceptionHandler(pqxx::work& txn) : txn(txn) {}

	void handle(const std::exception& e) {
		if (const auto* sqlError = dynamic_cast<const pqxx::sql_error*>(&e)) {
			if (std::string(sqlError->what()).find("duplicate key value violates unique constraint") != std::string::npos) {
				std::cerr << "������: �������� ��� ���������� � �������." << std::endl;
			}
			else {
				std::cerr << "������ ��� ���������� ��������: " << sqlError->what() << std::endl;
			}
		}
		else {
			std::cerr << "����� ������: " << e.what() << std::endl;
		}
		txn.abort(); // �������� ����������
	}

private:
	pqxx::work& txn;
};


#endif // EXCEPT_H
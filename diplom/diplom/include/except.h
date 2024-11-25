#ifndef EXCEPT_H
#define EXCEPT_H

#include <exception>
#include <string>

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

#endif // EXCEPT_H
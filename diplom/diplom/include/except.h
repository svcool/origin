#ifndef EXCEPT_H
#define EXCEPT_H

#include <exception>
#include <string>

class db_error : public std::exception {
    std::string message;
public:
    db_error(const std::string& message) : message{ message } {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // EXCEPT_H
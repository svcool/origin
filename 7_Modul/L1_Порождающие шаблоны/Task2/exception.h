#pragma once
#include "Query.h"

class QueryException : public std::exception {
    std::string message;
public:
    QueryException(const std::string& message) : message(message) {};
    
    const char* what() const noexcept override {
    return message.c_str();
    }
};
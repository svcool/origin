#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

enum class Type {
    Info,
    Warning,
    Error,
    FatalError,
    Unknown
 };

class LogMessage {
    Type messageType;
    std::string messageText;
public:
    LogMessage(Type type, const std::string& message) : messageType(type), messageText(message) {}

    Type type() const {
        return messageType;
    }

    const std::string& message() const {
        return messageText;
    }
};

void handleLogMessage(const LogMessage& logMessage, const std::string& filePath) {
    std::ofstream file(filePath, std::ios::app);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file for writing");
    }

    switch (logMessage.type()) {
    case Type::FatalError:
        throw std::runtime_error("Fatal Error: " + logMessage.message());
        break;
    case Type::Error:
        file << "Error: " << logMessage.message() << std::endl;
        break;
    case Type::Warning:
        std::cout << "Warning: " << logMessage.message() << std::endl;
        break;
    case Type::Unknown:
        throw std::runtime_error("Unknown Message: " + logMessage.message());
        break;
    default:
        std::cout << "Info: " << logMessage.message() << std::endl;
        break;
    }
}

int main() {
    LogMessage infoMessage(Type::Info, "This is an informational message");
    LogMessage warningMessage(Type::Warning, "This is a warning message");
    LogMessage errorMessage(Type::Error, "This is an error message");
    LogMessage fatalErrorMessage(Type::FatalError, "This is a fatal error message");
    LogMessage unknownMessage(Type::Unknown, "This is an unknown message");

    std::string filePath = "errorlog.txt";
    try {
        handleLogMessage(infoMessage, filePath);
        handleLogMessage(warningMessage, filePath);
        handleLogMessage(errorMessage, filePath);
        handleLogMessage(fatalErrorMessage, filePath);
        handleLogMessage(unknownMessage, filePath);
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
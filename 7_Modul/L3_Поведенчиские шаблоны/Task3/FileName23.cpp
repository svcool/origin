#include <iostream>
#include <stdexcept>
#include <string>

class ExceptionHandler : public std::exception {
	std::string message;
public:
	ExceptionHandler(const std::string& message) :message(message) {};

	const char* what() const noexcept override {
		return message.c_str();
	}
};

enum class Type {
	Info,
	Warning,
	Error,
	FatalError,
	Unknown
};

class LogMessage {
private:
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

class LogHandler {
private:
	LogHandler* nextHandler;

public:
	LogHandler() : nextHandler(nullptr) {}

	void setNextHandler(LogHandler* handler) {
		nextHandler = handler;
	}

	virtual void handleLogMessage(const LogMessage& logMessage) = 0;

	void passToNext(const LogMessage& logMessage) {
		if (nextHandler) {
			nextHandler->handleLogMessage(logMessage);
		}
	}
};

class FatalErrorHandler : public LogHandler {
public:
	void handleLogMessage(const LogMessage& logMessage) override {
		if (logMessage.type() == Type::FatalError) {
			ExceptionHandler("Fatal Error: " + logMessage.message());
		}
		else {
			passToNext(logMessage);
		}
	}
};

class ErrorHandler : public LogHandler {
public:
	void handleLogMessage(const LogMessage& logMessage) override {
		if (logMessage.type() == Type::Error) {
			std::cerr << "Error: " << logMessage.message() << std::endl;
		}
		else {
			passToNext(logMessage);
		}
	}
};

class WarningHandler : public LogHandler {
public:
	void handleLogMessage(const LogMessage& logMessage) override {
		if (logMessage.type() == Type::Warning) {
			std::cout << "Warning: " << logMessage.message() << std::endl;
		}
		else {
			passToNext(logMessage);
		}
	}
};

class UnknownMessageHandler : public LogHandler {
public:
	void handleLogMessage(const LogMessage& logMessage) override {
		if (logMessage.type() == Type::Unknown) {

			std::cout << "Unknown Message: " << logMessage.message() << std::endl;
		}
		else {
			ExceptionHandler("Unhandled Message: " + logMessage.message());
		}
	}
};

int main() {
	
	FatalErrorHandler fatalErrorHandler;
	ErrorHandler errorHandler;
	WarningHandler warningHandler;
	UnknownMessageHandler unknownMessageHandler;
	//установка цепочки
	errorHandler.setNextHandler(&fatalErrorHandler);
	warningHandler.setNextHandler(&errorHandler);
	unknownMessageHandler.setNextHandler(&warningHandler);

	LogMessage infoMessage(Type::Info, "This is an informational message");
	LogMessage warningMessage(Type::Warning, "This is a warning message");
	LogMessage errorMessage(Type::Error, "This is an error message");
	LogMessage fatalErrorMessage(Type::FatalError, "This is a fatal error message");
	LogMessage unknownMessage(Type::Unknown, "This is an unknown message");

	try {
		errorHandler.handleLogMessage(infoMessage);
		errorHandler.handleLogMessage(warningMessage);
		errorHandler.handleLogMessage(errorMessage);
		errorHandler.handleLogMessage(fatalErrorMessage);
		errorHandler.handleLogMessage(unknownMessage);
	}
	catch (const ExceptionHandler& err) {
		std::cout << "Error: " << err.what() << std::endl;
	}
	catch (const std::exception&){
		std::cout << "Something wrong" << std::endl;
	}
	return 0;
}

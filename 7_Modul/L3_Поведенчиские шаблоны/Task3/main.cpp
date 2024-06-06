﻿#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

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
			throw ExceptionHandler("Fatal Error: " + logMessage.message());
		}
		else {
			passToNext(logMessage);
		}
	}
};

class ErrorHandler : public LogHandler {
	std::string filePath;
	std::ofstream file;
public:
	ErrorHandler(const std::string path) : filePath(path) {
		file.open(path, std::ios::app);
	}
	void handleLogMessage(const LogMessage& logMessage) override {

		if (logMessage.type() == Type::Error) {
			if (file.is_open()) {
				file << "Error: " << logMessage.message() << std::endl;
			}
		}
		else {
			passToNext(logMessage);
		}
	}
	~ErrorHandler() {
		file.close();
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
			throw ExceptionHandler("Unhandled Message: " + logMessage.message());
		}
	}
};

int main() {

	LogMessage infoMessage(Type::Info, "This is an informational message");
	LogMessage warningMessage(Type::Warning, "This is a warning message");
	LogMessage errorMessage(Type::Error, "This is an error message");
	LogMessage fatalErrorMessage(Type::FatalError, "This is a fatal error message");
	LogMessage unknownMessage(Type::Unknown, "This is an unknown message");

	// сырой указтель и полиморфизм
	 /*LogHandler* fff = &fatalErrorHandler;
	fff->setNextHandler(&warningHandler);*/
	// c smart указатели
	std::unique_ptr<LogHandler> fatalErrorHandler = std::make_unique<FatalErrorHandler>();
	std::unique_ptr<LogHandler> errorHandler = std::make_unique<ErrorHandler>("output.txt");
	std::unique_ptr<LogHandler> warningHandler = std::make_unique<WarningHandler>();
	std::unique_ptr<LogHandler> unknownMessageHandler = std::make_unique<UnknownMessageHandler>();
	//цепочка
	fatalErrorHandler->setNextHandler(errorHandler.get());
	errorHandler->setNextHandler(warningHandler.get());
	warningHandler->setNextHandler(unknownMessageHandler.get());


	try {
		// вызов виртуальной функции
		fatalErrorHandler->handleLogMessage(warningMessage);
		fatalErrorHandler->handleLogMessage(errorMessage);
		fatalErrorHandler->handleLogMessage(unknownMessage);
		fatalErrorHandler->handleLogMessage(fatalErrorMessage); //исключение
		fatalErrorHandler->handleLogMessage(infoMessage); //исключение
	}
	catch (const ExceptionHandler& err) {
		std::cout << err.what() << std::endl;
	}
	catch (const std::exception&) {
		std::cout << "Something wrong" << std::endl;
	}
	////////без  умных указателей
		//FatalErrorHandler fatalErrorHandler;
		//ErrorHandler errorHandler("output.txt");
		//WarningHandler warningHandler;
		//UnknownMessageHandler unknownMessageHandler;
		//	
		////установка цепочки
		//fatalErrorHandler.setNextHandler(&errorHandler);
		//errorHandler.setNextHandler(&warningHandler);
		//warningHandler.setNextHandler(&unknownMessageHandler);

		//try {
		//	// вызов виртуальной функции
		//	fatalErrorHandler.handleLogMessage(warningMessage);
		//	fatalErrorHandler.handleLogMessage(errorMessage);
		//	fatalErrorHandler.handleLogMessage(unknownMessage);
		//	fatalErrorHandler.handleLogMessage(fatalErrorMessage); //исключение
		//	fatalErrorHandler.handleLogMessage(infoMessage); //исключение
		//}
		//catch (const ExceptionHandler& err) {
		//	std::cout << err.what() << std::endl;
		//}
		//catch (const std::exception&){
		//	std::cout << "Something wrong" << std::endl;
		//}
	return 0;
}

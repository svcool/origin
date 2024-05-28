#include <iostream>
#include <fstream>
#include <string>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

void print(LogCommand&);

class LogToFileCommand : LogCommand {
private:
    std::string message;
    std::string filePath;
public:
public:
    LogToFileCommand(const std::string& msg, const std::string& path) : message(msg), filePath(path) {}

    void print(Logger& logger) override {
        logger.logToFile(message, filePath);
    }
};

class LogPrintCommand : LogCommand {
private:
    std::string message;
public:
    LogPrintCommand(const std::string& msg) : message(msg) {}
    void print(Logger& logger) override {
        logger.logError(message);
    }
};



// Function to execute a command
void print(LogCommand& command) {
    command.print();
}


int main() {
    // Create command objects
    Command* infoCommand = new LogInfoCommand("This is an information message");
    Command* errorCommand = new LogErrorCommand("This is an error message");
    Command* fileCommand = new LogToFileCommand("This message is written to file", "log.txt");
    LogCommand log("This is a log message");

}


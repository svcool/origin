
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Receiver class
class Logger {
public:
    void logInfo(const std::string& message) {
        std::cout << "[INFO] " << message << std::endl;
    }

    void logError(const std::string& message) {
        std::cerr << "[ERROR] " << message << std::endl;
    }

    void logToFile(const std::string& message, const std::string& filePath) {
        std::ofstream file(filePath, std::ios::app);
        file << message << std::endl;
        file.close();
    }
};

// Base command interface
class Command {
public:
    virtual void execute(Logger& logger) = 0;
};

// Concrete commands
class LogInfoCommand : public Command {
private:
    std::string message;

public:
    LogInfoCommand(const std::string& msg) : message(msg) {}

    void execute(Logger& logger) override {
        logger.logInfo(message);
    }
};

class LogErrorCommand : public Command {
private:
    std::string message;

public:
    LogErrorCommand(const std::string& msg) : message(msg) {}

    void execute(Logger& logger) override {
        logger.logError(message);
    }
};

class LogToFileCommand : public Command {
private:
    std::string message;
    std::string filePath;

public:
    
    void execute(Logger& logger) override {
        logger.logToFile(message, filePath);
    }
};

// Invoker class
class LogManager {
private:
    std::vector<Command*> commands;

public:
    void addCommand(Command* command) {
        commands.push_back(command);
    }

    void executeAllCommands(Logger& logger) {
        for (Command* command : commands) {
            command->execute(logger);
        }
    }
};

int main() {
    Logger logger;
    LogManager logManager;

    // Create command objects
    Command* infoCommand = new LogInfoCommand("This is an information message");
    Command* errorCommand = new LogErrorCommand("This is an error message");
    Command* fileCommand = new LogToFileCommand("This message is written to file", "log.txt");

    // Add commands to LogManager
    logManager.addCommand(infoCommand);
    logManager.addCommand(errorCommand);
    logManager.addCommand(fileCommand);

    // Execute all commands
    logManager.executeAllCommands(logger);

    // Clean up memory
    delete infoCommand;
    delete errorCommand;
    delete fileCommand;

    return 0;
}

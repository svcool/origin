#include <iostream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

void print(LogCommand&);

int main() {


}


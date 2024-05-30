#include <iostream>
#include <vector>

class Logger {
    std::string msg;
    std::vector<Observer*> observers;
public:
    Warning(std::string message) : msg(message) {}
    void warning(const std::string& message) const {
        std::cout << "warning:" << msg << std::endl;
    }

};
class Error {
    std::string msg;
public:
    void error(const std::string& message) const {
        std::cout << "Error:" << msg << std::endl;
    };
};
class FatalError {
    std::string msg;
public:
    void fatalError(const std::string& message) const {
        std::cout << "FatalError:" << msg << std::endl;
    };
    ~Logger {
    
    }

    Этот объект должен :

    -уметь добавлять не владеющие указатели на наблюдателей,
        -оповещать наблюдателей о вызове каждого из методов,
        -корректно обрабатывать разрушение объектов - наблюдателей.
};


class Observer {
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};

class Warining : public Observer {
    void onWarning(const std::string& message) {
    std::cout << " Warning #1" << std::endl;
    }
        

};

class Error : public Observer {


};

class FatalError : public Observer {


};
-класс для работы с предупреждениями, который будет печатать сообщение в консоль;
-класс для работы с ошибками, который будет печатать сообщение в файл по указанному пути;
-класс для работы с фатальными ошибками, который будет печатать сообщение в консоль и в файл по указанному пути.

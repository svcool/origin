#include <iostream>
#include <vector>
#include <fstream>



class Observer {
    public:
        virtual void onWarning(const std::string& message) {};
        virtual void onError(const std::string& message) {};
        virtual void onFatalError(const std::string& message) {};
    virtual ~Observer() = default;
};

class Warining : public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << "Received a warning: " << message << std::endl;
    }
};

class Error : public Observer {
    std::string filePath = "output.txt";
    std::ofstream file;
public:
    Error(const std::string& path) {
        file.open(path, std::ios::app);
    }
    void onError(const std::string& message) override {
        if (file.is_open()) {
            ;
            file << "Received a error: " << message << std::endl;
        }
     }
    ~Error() {
        file.close();
    }


};

class FatalError : public Observer {
    std::string filePath = "output.txt";
    std::ofstream file;
public:
    FatalError(const std::string& path) {
        file.open(path, std::ios::app);
    }
    void onFatalError(const std::string& message) override {
        if (file.is_open()) {
           file << "Received a fatal error: " << message << std::endl;
        }
        std::cout << "Received a fatal error: " << message << std::endl;
    }

    ~FatalError() {
        file.close();
    }
};

class Logger {
    std::string msg;
    std::vector<std::weak_ptr<Observer>> observers;
public:
    //Добавлеям наблюдателей
    void attach(const std::shared_ptr<Observer>& obs) {
        observers.push_back(obs);
    }
    //Удаляем наблюдателей
    void detach(const std::shared_ptr<Observer>& obs) {
        auto it = std::find_if(observers.begin(), observers.end(),
            [&](const std::weak_ptr<Observer>& wp) {
                if (auto sp = wp.lock()) {
                    return (sp == obs);
                }
                return false;
            });

        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void warning(const std::string& msg) const {
        std::cout << "consol: " << std::endl;
        notify(msg,1);
    }

    void error(const std::string& msg) const {
        std::cout << "File: " << std::endl;
        notify(msg,2);
    }

    void fatalError(const std::string& msg) const {
        std::cout << "file and consol: " << std::endl;
        notify(msg,3);
    }


    //void notify(std::string msg) const {};
//Извещение наблюдателей
    void notify(const std::string& msg, const int& count) const {
        for (const std::weak_ptr<Observer> obs : observers) {
            if (!obs.expired()) {
                if (auto sptr = obs.lock()) {
                    switch (count) {
                    case 1:
                        sptr->onWarning(msg); break;
                    case 2:
                        sptr->onError(msg); break;
                    case 3:
                        sptr->onFatalError(msg); break;
                    }
                }
            }
        }
    }
};

   


int main() {
    setlocale(LC_ALL, "Russian");
    Logger subject;

    std::shared_ptr<Warining> warning  = std::make_shared<Warining>();
    std::shared_ptr<Error> error = std::make_shared<Error>("output.txt");
    std::shared_ptr<FatalError> fatalerror = std::make_shared<FatalError>("output.txt");
    subject.attach(warning);
    subject.attach(error);
    subject.attach(fatalerror);

    subject.warning("#####Warning №1#####");
    subject.error("#####Error №1######");
    subject.fatalError("####Fatal Error №1#####");

    return 0;
 }


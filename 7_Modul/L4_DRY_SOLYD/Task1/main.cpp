
#include <iostream>﻿
#include <fstream>
#include <string>

enum class Format
    {
        kText,
        kHTML,
        kJSON,
        end_enum //конец перечислений
    };

class Printable
{
public:
    virtual ~Printable() = default;
    virtual std::string print() const = 0;

};

class Data {

public:
    

    Data(std::string data, Format format) : data_(data), format_(format) {
        if (static_cast<int>(format) < 0 || static_cast<int>(format) >= static_cast<int>(Format::end_enum)) {
            throw std::runtime_error("Invalid format!");
        }
    }

protected:
  std::string data_;
  Format format_;  
};

class Format_AsHTML : protected Data, public Printable {
public:
    std::string print() const override {
        return "<html>" + data_ + "<html/>";
    }

    
};

class Format_AsText : protected Data, public Printable {
public:
std::string print() {
    return data_;
}
    
};
class Format_AsJSON : public Data, public Printable {
public:
    std::string print() {
       return "{ \"data\": \"" + data_ + "\"}";
    }
public:

    
};


void saveTo(std::ostream& stream, const Printable* printable)
{
    stream << printable->print();
}

void saveToAsHTML(std::ostream& stream, const Printable* printable) {
    Format_AsHTML format_AsHTML();
    printable = &format_AsHTML();
    saveTo(stream, printable);
}

void saveToAsJSON(std::ostream& stream, const Printable* printable) {
    Format_AsHTML format_AsText();
    printable = &format_AsText();
    saveTo(stream, printable);
}

void saveToAsText(std::ostream& stream, const Printable* printable) {
    Format_AsHTML format_AsJSON();
    printable = &format_AsJSON();
    saveTo(stream, printable);
}

//принцип инверсии зависимостей: функции зависят от cущности более низкого уровня std::ofstream. Тип данных должен быть максимально абвстрактным
//Абстрактный класс Printable должен быть максимально специализрован под конкретный формат данных. Нарушается принцип разделения интерфейсов
//Принцип открытости и закрытости: При добавлении другого формата потребуется изменять код в классе Data, также влечет изменения в функции SaveTo. Класс должен 
//сконструирован так, чтобы это не вело к изменению его кода.
//Принцип Лисков: потомок Data модифицирует метод print используя исключения, т.е. дополнительным условием. Нарушается прямой функционал метода из родителя.

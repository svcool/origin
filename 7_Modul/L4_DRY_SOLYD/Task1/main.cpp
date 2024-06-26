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

class Data : public Printable {
 public:
    Data(std::string data, Format format) : data_(data), format_(format) {
        /*if (static_cast<int>(format) < 0 || static_cast<int>(format) >= static_cast<int>(Format::end_enum)) {
            throw std::runtime_error("Invalid format!");
        }*/
    }
    std::string getdat() const {
        return data_;
    }
    std::string print() const override {
        return data_;
    }

    Format getformat() const {
        return format_;
    }


private:
Format format_;
std::string data_;    
      
};

class Format_AsHTML : public Data {
public:
    Format_AsHTML(const Data& data) : Data(data) {}
    std::string print() const override {
        return "<html>" + getdat() + "<html/>";
    }
};

class Format_AsText : public Data {
public:
    Format_AsText(const Data& data) : Data(data) {}
    std::string print() {
        return getdat();
    }

};
class Format_AsJSON : public Data {
public:
    Format_AsJSON(const Data& data) : Data(data) {}
    std::string print() {
        return "{ \"data\": \"" + getdat() + "\"}";
    }
public:
};


void saveTo(std::ostream& stream, const Printable& printable)
{
    stream << printable.print();
}

void saveToAsHTML(std::ostream& stream, Data& data) {
    if (data.getformat() != Format::kHTML) return;
    Format_AsHTML format_AsHTML(data);
    saveTo(stream, format_AsHTML);
}

void saveToAsJSON(std::ostream& stream, Data& data) {
    if (data.getformat() != Format::kJSON) return;
    Format_AsJSON format_AsJSON(data);
    saveTo(stream, format_AsJSON);

}

void saveToAsText(std::ostream& stream, Data& data) {
    if (data.getformat() != Format::kText) return;
    Format_AsText format_AsText(data);
    saveTo(stream, format_AsText);
}

int main() { 
    Data data("Hello, World!", Format::kHTML);
 
    std::ofstream text_file("text_file.txt");
    saveToAsText(text_file, data);
    text_file.close();

    std::ofstream html_file("html_file.txt");
    saveToAsHTML(html_file, data);
    html_file.close();

    std::ofstream json_file("json_file.txt");
    saveToAsJSON(json_file, data);
    json_file.close();

    return 0;
}
//принцип инверсии зависимостей: функции зависят от cущности более низкого уровня std::ofstream. Тип данных должен быть максимально абвстрактным
//Абстрактный класс Printable должен быть максимально специализрован под конкретный формат данных. Нарушается принцип разделения интерфейсов
//Принцип открытости и закрытости: При добавлении другого формата потребуется изменять код в классе Data, также влечет изменения в функции SaveTo. Класс должен 
//сконструирован так, чтобы это не вело к изменению его кода.
//Принцип Лисков: потомок Data модифицирует метод print используя исключения, т.е. дополнительным условием. Нарушается прямой функционал метода из родителя.

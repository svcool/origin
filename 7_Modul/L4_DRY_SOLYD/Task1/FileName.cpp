#include <iostream>
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
    Data() = default;
    Data(std::string data, Format format) : data_(data), format_(format) {}

    std::string print() const override {
        return data_;
    }

protected:
    std::string data_;
    Format format_;
};

class Format_AsHTML : public Printable {
public:
    Format_AsHTML(const Printable* data) : data_(data) {}

    std::string print() const override {
        return "<html>" + data_->print() + "</html>";
    }

private:
    const Printable* data;
};

class Format_AsText : public Printable {
public:
    Format_AsText(const Printable* data) : data_(data) {}

    std::string print() const override {
        return data_->print();
    }

private:
    const Printable* data;
};

class Format_AsJSON : public Printable {
public:
    Format_AsJSON(const Printable* data) : data_(data) {}

    std::string print() const override {
        return "{ \"data\": \"" + data_->print() + "\"}";
    }

private:
    const Printable* data;
};

void saveTo(std::ostream& stream, const Printable* printable) {
    stream << printable->print();
}

void saveToAsHTML(std::ostream& stream, const Printable* printable) {
    Format_AsHTML format_AsHTML(printable);
    saveTo(stream, &format_AsHTML);
}

void saveToAsJSON(std::ostream& stream, const Printable* printable) {
    Format_AsJSON format_AsJSON(printable);
    saveTo(stream, &format_AsJSON);
}

void saveToAsText(std::ostream& stream, const Printable* printable) {
    Format_AsText format_AsText(printable);
    saveTo(stream, &format_AsText);
}

int main() {
    Data data("Hello, World!", Format::kText);

    std::ofstream text_file("text_file.txt");
    saveToAsText(text_file, &data);
    text_file.close();

    std::ofstream html_file("html_file.html");
    saveToAsHTML(html_file, &data);
    html_file.close();

    std::ofstream json_file("json_file.json");
    saveToAsJSON(json_file, &data);
    json_file.close();

    return 0;
}
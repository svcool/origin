#include <string>
#include <iostream>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}

    virtual void render(const std::string& data1, const std::string& data2) const {}

    void render(const std::string& data1) const override {
        text_->render(data1);
    };
    
    
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText {
public:
    explicit Paragraph(Text* text_) :DecoratedText(text_) {}
void render(const std::string& data) const {
    std::cout << "<p>";
    text_->render("Hello world");
    std::cout << "</p>";
}
};

class Reversed : public DecoratedText {
    
public:
    
    explicit Reversed(Text* text_) : DecoratedText(text_) {}
    void render(const std::string& data) const {
        std::string& tx = const_cast<std::string&>(data); //снимаем константность ссылки и присваиваем новой переменной
        std::reverse(tx.begin(), tx.end());
        text_->render(tx);
    }
};


class Link : public DecoratedText {
public:
    using DecoratedText::render;

    explicit Link(Text* text_) : DecoratedText(text_) {}
    void render(const std::string& data1, const std::string& data2) const override {
        std::cout << "<a href =";
        std::cout << data1;
        std::cout << ">";
        text_->render(data2);
        std::cout << "</a>";
    }

};

int main() {
    auto text_block = new ItalicText(new BoldText(new Text()));
    text_block->render("Hello world");
    std::cout << std::endl;
    auto text_block1 = new Paragraph(new Text());
    text_block1->render("Hello world");	
    std::cout << std::endl;
    auto text_block2 = new Reversed(new Text());
    text_block2->render("Hello world"); 
    
    auto text_block = new Link(new Text());
    text_block->render("netology.ru", "Hello world");
}
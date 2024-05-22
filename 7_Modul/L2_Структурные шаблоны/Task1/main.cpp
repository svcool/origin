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

int main() {
    auto text_block = new ItalicText(new BoldText(new Text()));
    text_block->render("Hello world");
}



В программу рендеринга HTML из лекции(раздел про паттерн «Декоратор») добавьте новые классы для декорирования текста.
```
class Paragraph : ...

	auto text_block = new Paragraph(new Text());
text_block->render("Hello world");

>> > <p>Hello world< / p>
```

```
class Reversed : ...

	auto text_block = new Reversed(new Text());
text_block->render("Hello world");

>> > dlrow olleH
```

```
class Link : ...

	auto text_block = new Link(new Text());
text_block->render("netology.ru", "Hello world");

>> > <a href = netology.ru>Hello world< / a>
```
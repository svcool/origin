#include <iostream>
#include <vector>
#include <ctime>
class View { // Базовый класс окошка, которое видит пользователь
public:
	View(int x, int y, int width, int height) // Кординаты позиции на экране и размер окошка
		: x_(x), y_(y), width_(width), height_(height) {}
	
	virtual ~View() = default;

	bool containsClick(int x, int y) const { // Определяем пришёлся ли клик в окошко
		return x >= x_ && x <= x_ + width_ && y >= y_ && y <= y_ + height_;
	}

	void addSubview(std::unique_ptr<View> view) { // Встраиваем другое окошко поверх текущего
		view->parent_ = this;
		subviews_.push_back(std::move(view));
	}

	void handleClick(int x, int y) {
		if (containsClick(x, y)) {
			std::cout << "Clicked view " << this << " at " << x << ":" << y << std::endl;
			onClick(); // Обрабатываем клик если он пришёлся в это окошко
			return;
		}
		if (parent_) {
			parent_->handleClick(x, y); // Иначе пробрасываем клик в родительское окошко
		}
	}

	virtual void onClick() {} // Обработка клика переопределяется в классах-наследниках

private:
	std::vector<std::unique_ptr<View>> subviews_;
	View* parent_ = nullptr;
	int x_ = 0;
	int y_ = 0;
	int width_ = 0;
	int height_ = 0;
};

class Button : public View {
public:
	Button(int x, int y, int width, int height) : View(x, y, width, height) {}
	
	void onClick() override {
		std::cout << "Clicked button " << this << std::endl;
	}
};

int main() {
	auto root = std::make_unique<View>(0, 0, 256, 256); // Создаём основное окошко
	auto button = std::make_unique<Button>(50, 50, 25, 25); // Создаём кнопку
	auto* foregroundView = button.get(); // Окошко перед пользователем
	root->addSubview(std::move(button)); // Встраиваем кнопку в основное окошко
	foregroundView->handleClick(56, 70); // Кликаем в кнопку
	foregroundView->handleClick(160, 130); // Кликаем мимо кнопки
}
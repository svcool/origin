#include <iostream>
#include <vector>
#include <ctime>
class View { // ������� ����� ������, ������� ����� ������������
public:
	View(int x, int y, int width, int height) // ��������� ������� �� ������ � ������ ������
		: x_(x), y_(y), width_(width), height_(height) {}
	
	virtual ~View() = default;

	bool containsClick(int x, int y) const { // ���������� �������� �� ���� � ������
		return x >= x_ && x <= x_ + width_ && y >= y_ && y <= y_ + height_;
	}

	void addSubview(std::unique_ptr<View> view) { // ���������� ������ ������ ������ ��������
		view->parent_ = this;
		subviews_.push_back(std::move(view));
	}

	void handleClick(int x, int y) {
		if (containsClick(x, y)) {
			std::cout << "Clicked view " << this << " at " << x << ":" << y << std::endl;
			onClick(); // ������������ ���� ���� �� �������� � ��� ������
			return;
		}
		if (parent_) {
			parent_->handleClick(x, y); // ����� ������������ ���� � ������������ ������
		}
	}

	virtual void onClick() {} // ��������� ����� ���������������� � �������-�����������

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
	auto root = std::make_unique<View>(0, 0, 256, 256); // ������ �������� ������
	auto button = std::make_unique<Button>(50, 50, 25, 25); // ������ ������
	auto* foregroundView = button.get(); // ������ ����� �������������
	root->addSubview(std::move(button)); // ���������� ������ � �������� ������
	foregroundView->handleClick(56, 70); // ������� � ������
	foregroundView->handleClick(160, 130); // ������� ���� ������
}
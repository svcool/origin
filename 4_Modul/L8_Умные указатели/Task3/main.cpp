#include <iostream>
using namespace std;

class base
{
public:
	base() { std::cout << "base constructor\n"; }
	virtual ~base() = default;
	virtual void func() { std::cout << "func in base class\n"; }
};
struct derived : public base
{
	derived() { std::cout << "derived constructor\n"; }
	void func() override { std::cout << "func in derived class\n"; }
};


template <class T>
class unique_pt {
	T* ptr;
public:
	
	unique_pt(T* ptr) :ptr(ptr) {}
	// разыменовывание
	T& operator*() {
		return *ptr;
	}
	//запрет копирования
	unique_pt(const unique_ptr<T>& other) = delete;
	//запрет оператора присваивания
	unique_pt& operator=(const unique_pt& other) = delete;
	// переопределение ->
	T* operator-> () { return ptr; }

	T* release() {
		T* ptr_new = ptr;
		ptr = nullptr;
		return ptr_new;
	}

	~unique_pt() {
		delete ptr;
		cout << "destructor called";
	}
	};

int main() {
	unique_pt<int> ptr = new int(5);
	cout << "address ptr: " << &*ptr << "\n";
	ptr.release();
	cout << "address ptr ofter release: " << &*ptr << "\n";

	//derived der;
	unique_pt<base> ptr1(new derived());
	ptr1->func();
	cout << "address ptr1: " << & ptr << "\n";
	
}
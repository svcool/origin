#include <iostream>
#include <mutex>
#include <algorithm>

//Защищённый обмен данными
//
//- Создайте класс Data, содержащий в качестве полей скалярные данные и мьютекс.
//- Создайте функцию swap, которая принимает ссылки на два объекта класса Data и обменивает их местами.<br / >
//-В функциях нужно сначала захватить мьютексы обоих объектов, а затем выполнить обмен данными.
//- Реализуйте три варианта этой функции : при помощи lock, scoped_lock и unique_lock.


class Data {
	
public:
	Data(int a) : a(a) {
		
	}
	int a{};
	std::mutex mt;
	int get_a() {
		return a;
	}
};

void swap_lock(Data& x, Data& y) {
	if (&x == &y) // проверка, объекты не идентичны
		return;
	lock(x.mt,y.mt);
	std::lock_guard lock1{ x.mt, std::adopt_lock };
	std::lock_guard lock2{ y.mt, std::adopt_lock };
	std::swap(x.a, y.a);
	//x.mt.unlock();
	//y.mt.unlock();
	}

void swap_scoped_lock(Data& x, Data& y) {
	if (&x == &y) // проверка, объекты не идентичны
		return;
	std::scoped_lock lock(x.mt, y.mt);
	std::swap(x.a, y.a);
	}

void swap_unique_lock(class Data& x, class Data& y) {
	if (&x == &y) // проверка, объекты не идентичны
		return;
	std::unique_lock<std::mutex> lock_x(x.mt,std::defer_lock);
	std::unique_lock<std::mutex> lock_y(y.mt, std::defer_lock);
	std::lock(lock_x, lock_y);
	//c(std::move(x)); x = std::move(y); y = std::move(c);
	std::swap(x.a, y.a);
	}

int main() {
	Data x(10);
	Data y(20);
	std::cout << x.get_a() << " " << y.get_a() << "\n";
	
	std::thread t1(swap_scoped_lock, std::ref(x), std::ref(y));
	//std::thread t2(swap_scoped_lock, std::ref(x), std::ref(y));

	std::thread t3(swap_lock, std::ref(x), std::ref(y));
	std::thread t4(swap_lock, std::ref(x), std::ref(y));

	std::thread t5(swap_unique_lock, std::ref(x), std::ref(y));
	std::thread t6(swap_unique_lock, std::ref(x), std::ref(y));

	t1.join();
	//t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();

	std::cout << x.get_a() << " " << y.get_a();
}
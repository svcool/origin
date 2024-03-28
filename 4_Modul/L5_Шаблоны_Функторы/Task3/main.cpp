#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
class functor {
	vector<T> vec;
	T result_sum{};
	T result_count{};
public:
	functor(const vector<T> vec_):vec(vec_) {};
	void operator() () {
		for (T n : vec) {
			if (n % 3 == 0) result_sum += n;
		}
		for (T n : vec) {
			if (n % 3 == 0) result_count++;
		}	
	}

	int get_sum() {
		return result_sum;
	}

	int get_count() {
		return result_count;
	}
};

//template <class T>
//class functor_count {
//	vector<T> vec;
//	T result{};
//public:
//	functor_count(vector<T> vec_) :vec(vec_) {};
//	T operator() () {
//		for (T n : vec) {
//			if (n % 3 == 0) result++;
//		}
//		return result;
//	}
//	int get_res() {
//		return result;
//	}
//};

//void print(int value) {
//	cout << value << " ";
//}


int main() {
vector<int> v1{4, 1, 3, 6, 25, 54};
	functor<int> fun(v1);
	cout << "[IN]: ";
	//for_each(v1.begin(), v1.end(), print);
	for_each(v1.begin(), v1.end(), [](int a) {cout << a << " "; });
	
	fun();

	cout << "\n[OUT]: get_sum() = ";
	cout << fun.get_sum();
	cout << "\n[OUT]: get_count() = ";
	cout << fun.get_count() << "\n";
	
}

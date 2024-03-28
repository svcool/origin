#include <iostream>
#include <vector>

using namespace std;
//две реализации функции возведения в квадрат
template <class T> const T square(const T&);
template <class T> void square(vector<T>&);
//вывод вектора
template <class T> void printVector(const vector<T>&);

int main() {
	int a{5};
	cout << "[IN]: " << a << "\n";
	cout << "[OUT]: " << square(a) << "\n";

	vector<int> v1{3,6,8};
	cout << "[IN]: "; 
	printVector(v1);
	square(v1);
	cout << "[OUT]: ";
	printVector(v1);
}
template <class T> const T
square(const T& a) {
	return a * a;
}
template <class T> void square(vector<T>& vec) {
	for (unsigned i{}; i < vec.size(); i++) {
		vec[i] = vec[i] * vec[i];
	}
}

template <class T>
void printVector(const vector<T>& v1) {
	for (int i = 0; i < v1.size(); i++) {
		if (i != v1.size() - 1) cout << v1[i] << ", ";
		else cout << v1[i];
	}
	cout << "\n";
}

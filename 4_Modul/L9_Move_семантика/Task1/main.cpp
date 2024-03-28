#include <iostream>
#include <vector>

using namespace std;

template<class T>
void move_vectors(T& v1, T& v2) {
	v2 = std::move(v1);

}

int main(){
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;
	move_vectors(one, two);
	for (auto n : two) {
		cout << n << " ";
	}
	cout << "\n";
	for (auto n : one) {
		cout << n << " ";
	}
}
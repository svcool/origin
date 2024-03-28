#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>

template<class T>
void print(const T& cont) {
	/*for (auto n : cont) {
		std::cout << n << " ";
	}*/

	for_each(cont.begin(), cont.end(), [](auto a) {std::cout << a << " "; });
}

int main() {
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	std::cout << "Set: ";  print(test_set);

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	std::cout << "\nList: "; print(test_list);

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	std::cout << "\nVector: "; print(test_vector);

	return 0;
}
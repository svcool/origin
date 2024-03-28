#include <iostream>
#include <set>
#include <algorithm>

int main() {
	int a;
	std::set<int> s;

	//std::set<int, std::greater<int>> s; сортирует по возрастанию сразу

	std::cout << "[IN]: \n";
	while (std::cin >> a) {
		s.insert(a);
	}
	std::cout << "[OUT]: \n";
	////по возрастанию
	//for (auto it = s.begin(); it != s.end(); ++it) {
	//	std::cout << *it << "\n";
	//}
	////по убыванию
	//for (std::set<int>::reverse_iterator it = s.rbegin(); it != s.rend(); ++it) {
	//	std::cout << *it << "\n";
	//}

	//по убыванию
	for_each(s.rbegin(), s.rend(), [](int a) {std::cout << a << "\n"; });
	
	return 0;
}
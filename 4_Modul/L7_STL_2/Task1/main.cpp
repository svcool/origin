#include <iostream>
#include <vector>
#include <algorithm>

template <class T> void remove_dubl(T& vec) {
	std::sort(vec.begin(), vec.end(), [](const int i1, const int i2) {return i1 < i2;});
	auto it = std::unique(vec.begin(), vec.end());
	vec.erase(it, vec.end());
}

int main() {
	std::vector<int> vec{ 1, 1, 2, 5, 6, 1, 2, 4 };
	
	std::cout << "[IN]: ";
	for_each(vec.begin(), vec.end(), [](int a) {std::cout << a << " "; });
	// удаление дубликатов
	remove_dubl(vec);
	
	std::cout << "\n[OUT]: ";
	for_each(vec.begin(), vec.end(), [](int a) {std::cout << a << " "; });
	return 0;
}
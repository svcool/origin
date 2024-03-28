#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

int main() {
	std::string str{"Hello world!!"};
	std::cout << "[IN]: " << str;
	
	std::map<char, int> m;
	for (const auto i : str) {
		m[i] += 1;
	}
	//вектор из map
	std::vector<std::pair<char, int>> vec(m.begin(), m.end());
	//сортировка
	std::sort(vec.begin(), vec.end(), [](const std::pair< char, int >& i1, const std::pair< char, int >& i2) {
		return i1.second > i2.second; 
		}
	);

	std::cout << "\n[OUT]: \n";
	for (auto i : vec) {
		std::cout << i.first << ": " << i.second << "\n";
	}
	return 0;
}


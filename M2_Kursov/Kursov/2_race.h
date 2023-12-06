#pragma once
#include <iostream>

class Race {
	int type{};
	int distance{};
	std::string name;
public:
	Race(int type, int distance, std::string name) : type(type), distance(distance), name(name) {}
	int get_type() {
		return type;
	}
	int get_distance() {
		return distance;
	}
	std::string get_name() {
		return name;
	}

};
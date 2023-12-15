#pragma once
#include <iostream>

class Race {
	int type{};
	double distance{};
	std::string name;
public:
	Race(int type, double distance, std::string name);
	int get_type();
	double get_distance();
	std::string get_name();
};
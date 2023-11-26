#pragma once
#include <iostream>
class Greeter {
	std::string name{};
public:
	Greeter(std::string name);
	void greet(std::string name);
};

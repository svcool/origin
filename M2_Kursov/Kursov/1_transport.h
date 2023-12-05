#pragma once
#include <iostream>

class Transport {
protected:
	std::string name;
	Transport(std::string name) :name(name) {}
};
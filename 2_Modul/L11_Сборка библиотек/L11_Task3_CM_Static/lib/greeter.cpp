#include "greeter.h"
	Greeter::Greeter(std::string name) :name(name) {};
	void Greeter::greet(std::string name) {
		this->name = name;
		std::cout << "До свидания, " << name << "!" << std::endl;

	}
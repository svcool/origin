#include "leaver.h"
Leaver::Leaver(std::string name) :name(name) {};
	void Leaver::leave(std::string name) {
		this->name = name;
		std::cout << "������������, " << name << "!" << std::endl;

	}
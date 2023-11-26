#include "leaver.h"
Leaver::Leaver(std::string name) :name(name) {};
	void Leaver::leave(std::string name) {
		this->name = name;
		std::cout << "До свидания " << name << "!" << std::endl;

	}
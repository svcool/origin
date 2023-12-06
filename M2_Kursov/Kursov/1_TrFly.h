#pragma once
#include "1_transport.h"
class T_fly :public Transport {
protected:
	int type{};
public:
	T_fly(int type, std::string name) :Transport(name) {
		this->type = type;
		name = "Воздушный транспорт";
	}
};

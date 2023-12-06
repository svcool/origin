#pragma once
#include "1_transport.h"
class T_ground:public Transport {
protected:	
	int type{}; 
	//std::string name;
public:
	T_ground(int type, std::string name) : Transport(name) {
		this->type = type;
		name = "Наземный транспорт";
	}
};

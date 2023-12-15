#pragma once
#include "1_Transport.h"
class T_fly :public Transport {
protected:
	int type;
public:
	T_fly(int type, std::string name);
};
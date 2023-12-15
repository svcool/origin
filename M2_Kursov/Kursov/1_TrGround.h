#pragma once
#include "1_Transport.h"
class T_ground :public Transport {
protected:
	int type{};
public:
	T_ground(int type, std::string name);
};
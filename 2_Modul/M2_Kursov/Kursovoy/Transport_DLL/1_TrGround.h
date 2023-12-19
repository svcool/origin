#pragma once
#include "1_Transport.h"
class T_ground :public Transport {
protected:
	int type{};
public:
	KURS_TRANSPORT_LIB_API T_ground(int type, std::string name);
};
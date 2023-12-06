#pragma once
#include "1_transport.h"
class Eagle : public T_fly {
public:
	Eagle(int type, std::string name) : T_fly(type, name) {}
};

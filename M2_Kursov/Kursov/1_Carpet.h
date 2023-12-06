#pragma once
#include "1_transport.h"
#include "1_TrGround.h"
class Carpet : public T_ground {
public:
	Carpet(int type, std::string name) : T_ground(type, name) {}
	std::string get_name() { return name; }
};

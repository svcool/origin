#pragma once
#include <iostream>
#include "1_TrFly.h"
#include "1_TrGround.h"
#include "1_Boots.h"
#include "1_Broom.h"
#include "1_Camel.h"
#include "1_CamelFast.h"
#include "1_Eagle.h"
#include "1_Kentavr.h"
#include "1_Carpet.h"

class Transport {
protected:
	std::string name;
	Transport(std::string name) :name(name) {}
};
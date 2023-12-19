#include "2_RaceFly.h"
Race_fly::Race_fly(std::string name, int type):Race(distance), name(name), type(type){}
int Race_fly::get_type() { return type; }
double Race_fly::get_distance() { return distance; }
std::string Race_fly::get_name() { return name; }
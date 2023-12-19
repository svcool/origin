#include "2_RaceGround.h"
Race_ground::Race_ground(std::string name, int type) :Race(distance), name(name), type(type) {}
int Race_ground::get_type() { return type; }
double Race_ground::get_distance() { return distance; }
std::string Race_ground::get_name() { return name; }
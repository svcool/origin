#include "2_RaceGroundFly.h"
Race_groundfly::Race_groundfly(std::string name, int type) :Race(distance), name(name), type(type) {}
int Race_groundfly::get_type() { return type; }
double Race_groundfly::get_distance() { return distance; }
std::string Race_groundfly::get_name() { return name; }
#include "2_Race.h"	
Race::Race(double distance) : distance(distance) {}
int Race::get_type() { return 0; }
double Race::get_distance() { return 0; }
std::string Race::get_name() { return ""; }
void Race::set_distance(double dist) { distance = dist; };
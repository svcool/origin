#include "2_Race.h"	
Race::Race(int type, double distance, std::string name) : type(type), distance(distance), name(name) {}
	int Race::get_type() { return type;}
	double Race::get_distance() {	return distance;}
	std::string Race::get_name() {return name;}
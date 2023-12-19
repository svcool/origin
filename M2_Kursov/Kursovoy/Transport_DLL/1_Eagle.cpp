#include "1_Eagle.h"
	Eagle::Eagle(int type, std::string name) : T_fly(type, name) {}
	void Eagle::set_move(double speed, int kp1) {
		speed_move = speed;
		k1 = kp1;
	}
	const std::string& const Eagle::get_name() const { return name; }
	int Eagle::get_type() { return type; }
	int Eagle::get_count() { return count; }
	void Eagle::set_count(int cn) { this->count = cn; }
	void Eagle::set_distance(double dist) { distance = dist; }
	double Eagle::comp() {
		double t = (distance - static_cast<double>(distance * k1/100) )/ speed_move;
		return t;
	}
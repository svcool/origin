#include "1_Broom.h"
	Broom::Broom(int type, std::string name) : T_fly(type, name) {}
	void Broom::set_move(int speed) {speed_move = speed;}
	const std::string& Broom::get_name() const { return name; }
	int Broom::get_type() { return type; }
	int Broom::get_count() { return count; }
	void Broom::set_count(int cn) { this->count = cn; }
	void Broom::set_distance(double dist) { distance = dist; }
	double Broom::comp() {
		int k{};
		int dist = static_cast<int>(distance);
		do {
			k = dist;
			dist /= 10;
		} while (dist);
		double t = (distance - static_cast<double>(distance * k / 100)) / speed_move;
		return t;
	};
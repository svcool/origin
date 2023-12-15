#include "1_Carpet.h"
	Carpet::Carpet(int type, std::string name) : T_fly(type, name) {}
	
	void Carpet::set_move(double speed, int kp1, int kp2, int kp3) {
		speed_move = speed;
		k1 = kp1; k2 = kp2; k3 = kp3;
	}
	const std::string Carpet::get_name() { return name; }
	int Carpet::get_type() { return type; }
	int Carpet::get_count() { return count; }
	void Carpet::set_count(int cn) { this->count = cn; }
	void Carpet::set_distance(double dist) { distance = dist; }
	double Carpet::comp() {
		k1 = 100 - k1; k2 = 100 - k2; k3 = 100 - k3;
		double t{};
		if (distance >= 10000) {
			t = (distance * k3) / static_cast<double>(speed_move);
			return t;
		}
		else if (distance >= 5000) {
			t = (distance * k2) / static_cast<double>(speed_move);
			return t;
		}
		else if (distance >= 1000) {
			t = (distance * k1) / static_cast<double>(speed_move);
			return t;
		}
		else return (static_cast<double>(distance) / static_cast<double>(speed_move));
	}
};
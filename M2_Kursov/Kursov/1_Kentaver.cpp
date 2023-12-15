#include "1_Kentavr.h"
	Kentavr::Kentavr(int type, std::string name) : T_ground(type, name) {}
	void Kentavr::set_move(double speed, double tm, double t1) {
		speed_move = speed;
		time_move = tm;
		time_out1 = t1;
	}
	const std::string Kentavr::get_name() { return name; }
	int Kentavr::get_type() { return type; }
	int Kentavr::get_count() { return count; }
	void Kentavr::set_count(int cn) { this->count = cn; }
	void Kentavr::set_distance(double dist) { distance = dist; }
	double Kentavr::comp() {
		double t{}; // общее время
		double distance_move = speed_move * time_move; // расстояние без отдыха
		double distance_parts = distance / distance_move; // количество частей дистанции
		double distance_ostatok = static_cast<int>(distance) % static_cast<int>(distance_move); // некратный остаток
		if (distance >= distance_move) {
			t = distance_parts * (time_move + time_out1) + distance_ostatok / speed_move;
			if (distance_ostatok == 0) t = t - time_out1;
			return t;
		}
		else return distance / speed_move;
	}

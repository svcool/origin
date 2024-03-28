#include "1_Boots.h"

	Boots::Boots(int type, std::string name) : T_ground(type, name) {}
	void Boots::set_move(double  speed, double  tm, double t1, double t2) {
		speed_move = speed;
		time_move = tm;
		time_out1 = t1, time_out2 = t2;
	}
	const std::string& Boots::get_name() const { return name; }
	int Boots::get_type() { return type; }
	int Boots::get_count() { return count; }
	void Boots::set_count(int cn) { this->count = cn; }
	void Boots::set_distance(double  dist) { distance = dist; }
	double Boots::comp() {
		double t{}; // ����� �����
		double  distance_move = speed_move * time_move; // ���������� ��� ������
	if (distance >= distance_move) {
		double  distance_ostatok_move1 = distance - distance_move; //���������� ���������� ����� 1�� ������
		int  distance_parts = static_cast<int>(distance_ostatok_move1 / distance_move); // ���������� ���������� ������ 
		double distance_ostatok = distance_ostatok_move1 - distance_parts*distance_move ; // ���������� ���������� ����������
			t = time_move + time_out1 + distance_parts * (time_move + time_out2) + distance_ostatok / speed_move;
			if (distance_ostatok == 0) t = t - time_out2;
			if (distance_ostatok_move1 == 0) t = t - time_out1;
			return t;
		}
		else return distance / speed_move;
	}

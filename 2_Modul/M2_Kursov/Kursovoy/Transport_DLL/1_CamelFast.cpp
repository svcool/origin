#include "1_CamelFast.h"
Camel_fast::Camel_fast(int type, std::string name) : T_ground(type, name) {}
	void Camel_fast::set_move(double speed, double tm, double t1, double t2, double t3) {
		speed_move = speed;
		time_move = tm;
		time_out1 = t1, time_out2 = t2; time_out3 = t3;
	}
	const std::string& Camel_fast::get_name() const { return name; }
	int Camel_fast::get_type() { return type; }
	int Camel_fast::get_count() { return count; }
	void Camel_fast::set_count(int cn) { this->count = cn; }
	void Camel_fast::set_distance(double dist) { distance = dist; }
	double Camel_fast::comp() {
		double t{}; // ����� �����
		double distance_move = speed_move * time_move; // ���������� ��� ������
		if (distance >= 2 * distance_move) {
		double distance_ostatok_move = distance - 2 * distance_move; //���������� ���������� ����� 2� �������
		int distance_parts = static_cast<int>(distance_ostatok_move / distance_move); // ���������� ���������� ������ 
		double distance_ostatok = distance_ostatok_move - distance_parts*distance_move; // ��������� �������
			t = 2 * time_move + time_out1 + time_out2 + distance_parts * (time_move + time_out3) + distance_ostatok / speed_move;
			if (distance_ostatok == 0) t = t - time_out3;
			if (distance_ostatok_move == 0) t = t - time_out2;
			return t;
		}
		else if (distance >= distance_move) {
			double distance_ostatok_move = distance - distance_move; //���������� ���������� ����� 1�� ������
			t = distance_move + time_out1 + distance_ostatok_move / speed_move;
			if (distance_ostatok_move == 0) t = t - time_out1;
			return t;
		}
		else  return distance / speed_move;
	}

#pragma once
#include "1_Transport.h"
class Camel_fast :public T_ground {
	int count{};
	double distance{};
	double speed_move{};
	double time_move{}, time_out1{}, time_out2{}, time_out3{};
public:
	Camel_fast(int type, std::string name);
	void set_move(double speed, double tm, double t1, double t2, double t3);
	const std::string get_name() override;
	int get_type() override;
	int get_count() override;
	void set_count(int cn) override;
	void set_distance(double dist);
	double comp();
};
#pragma once
#include "1_Transport.h"
class Kentavr :public T_ground {
	int count{};
	double distance{};
	double speed_move{};
	double time_move{}, time_out1{};
public:
	Kentavr(int type, std::string name);
	void set_move(double speed, double tm, double t1);
	const std::string get_name() override;
	int get_type() override;
	int get_count() override;
	void set_count(int cn) override;
	void set_distance(double dist);
	double comp() override;
};
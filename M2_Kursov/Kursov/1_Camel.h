#pragma once
#include "1_Transport.h"
class Camel : public T_ground {
	int count{};
	double distance{};
	double speed_move{};
	double time_move{}, time_out1{}, time_out2{};
public:
	Camel(int type, std::string name);
	const std::string get_name() override;
	void set_move(double speed, double tm, double t1, double t2);
	int get_type() override;
	int get_count() override;
	void set_count(int cn) override;
	void set_distance(double dist) override;
	double comp() override;
};
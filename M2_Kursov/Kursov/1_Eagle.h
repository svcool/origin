#pragma once
#include "1_Transport.h"
class Eagle : public T_fly {
	int count{};
	double distance{};
	double speed_move{};
	int k1{};
public:
	Eagle(int type, std::string name);
	void set_move(double speed, int kp1);
	const std::string get_name() override;
	int get_type() override;
	int get_count() override;
	void set_count(int cn) override;
	void set_distance(double dist);
	double comp() override;
};
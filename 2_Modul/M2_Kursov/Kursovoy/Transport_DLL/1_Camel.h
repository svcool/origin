#pragma once
#include "1_TrGround.h"
class Camel : public T_ground {
	int count{};
	double distance{};
	double speed_move{};
	double time_move{}, time_out1{}, time_out2{};
public:
	KURS_TRANSPORT_LIB_API Camel(int type, std::string name);
	KURS_TRANSPORT_LIB_API const std::string& get_name() const override;
	KURS_TRANSPORT_LIB_API void set_move(double speed, double tm, double t1, double t2);
	KURS_TRANSPORT_LIB_API int get_type() override;
	KURS_TRANSPORT_LIB_API int get_count() override;
	KURS_TRANSPORT_LIB_API void set_count(int cn) override;
	KURS_TRANSPORT_LIB_API void set_distance(double dist) override;
	KURS_TRANSPORT_LIB_API double comp() override;
};
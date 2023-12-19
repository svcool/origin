#pragma once
#include "1_TrFly.h"
class Carpet : public T_fly {
	int count{};
	double distance{};
	double speed_move{};
	int k1{}, k2{}, k3{};
public:
	KURS_TRANSPORT_LIB_API Carpet(int type, std::string name);
	KURS_TRANSPORT_LIB_API 	void set_move(double speed, int kp1, int kp2, int kp3);
	KURS_TRANSPORT_LIB_API const std::string& get_name() const override;
	KURS_TRANSPORT_LIB_API int get_type() override;
	KURS_TRANSPORT_LIB_API int get_count() override;
	KURS_TRANSPORT_LIB_API void set_count(int cn) override;
	KURS_TRANSPORT_LIB_API void set_distance(double dist);
	KURS_TRANSPORT_LIB_API double comp() override;
};
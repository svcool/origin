#pragma once
#include "2_Race.h"
class Race_groundfly :public Race {
protected:
	int type;
	std::string name;
public:
	KURS_RACE_LIB_API Race_groundfly(std::string name, int type);
	KURS_RACE_LIB_API int get_type() override;
	KURS_RACE_LIB_API double get_distance() override;
	KURS_RACE_LIB_API std::string get_name() override;
};
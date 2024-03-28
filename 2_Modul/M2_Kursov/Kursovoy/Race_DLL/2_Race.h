#pragma once
#include <iostream>
#ifdef RACEDLL_EXPORTS
#define KURS_RACE_LIB_API  __declspec(dllexport)
#else
#define	KURS_RACE_LIB_API  __declspec(dllimport)
#endif

class Race {
protected:	
	double distance{};
public:
	KURS_RACE_LIB_API Race(double distance);
	KURS_RACE_LIB_API virtual int get_type();
	KURS_RACE_LIB_API virtual double get_distance();
	KURS_RACE_LIB_API virtual std::string get_name();
	KURS_RACE_LIB_API virtual void set_distance(double distance);
};
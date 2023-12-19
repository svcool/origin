#pragma once
#include <iostream>
#ifdef TRANSPORTDLL_EXPORTS
#define KURS_TRANSPORT_LIB_API __declspec(dllexport)
#else
#define	KURS_TRANSPORT_LIB_API __declspec(dllimport)
#endif
class Transport {
protected:
	std::string name{};
public:
	Transport(std::string name);
	virtual int get_type();
	virtual int get_count();
	virtual const std::string& get_name() const;
	virtual void set_count(int cn);
	virtual void set_distance(double dist);
	virtual double comp();
};
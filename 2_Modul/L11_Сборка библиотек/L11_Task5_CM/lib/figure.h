#pragma once
#include <iostream>
#ifdef main_dll_EXPORTS
#define TRIAN_LIB_API __declspec(dllexport)
#else
#define	TRIAN_LIB_API __declspec(dllimport)
#endif


class figure {
protected:
	std::string name;
public:
	virtual void print_info();
};
#pragma once
#include "exsept.h"
#include <iostream>
class figure {
protected:
	std::string name;
public:
	virtual void print_info();
	virtual void create_print_info();
	void get_name();
};
#pragma once
//#include <exception>
#include <stdexcept>
#include <typeinfo>
#include "Figure.h"

class Except : public std::domain_error
{
private:
	int value; 
public:
	Except(char* msg, int value);
  
};

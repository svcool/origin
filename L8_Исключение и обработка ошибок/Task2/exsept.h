#pragma once
//#include <exception>
#include <stdexcept>
#include <typeinfo>
#include "Figure.h"

class Except : public std::domain_error
{
public:
	Except(const std::string&);
// импорттируем конструктор из базового класса
	//using std::domain_error::domain_error;
  
};

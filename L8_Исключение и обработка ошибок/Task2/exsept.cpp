#include "exsept.h"
#include "figure.h"

Except::Except(char* msg, int value) : domain_error(msg) {
	this->value = value;
};
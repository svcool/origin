#pragma once
#include <iostream>
#ifdef main_dll_EXPORTS
	#define LEAVER_LIB_API __declspec(dllexport)
#else
	#define	LEAVER_LIB_API __declspec(dllimport)
#endif

class Leaver {
	std::string name{};
public:
	LEAVER_LIB_API Leaver(std::string name);
	LEAVER_LIB_API void leave(std::string name);
};

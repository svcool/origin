#include "timer.h"

Timer::Timer() {
	start = std::chrono::high_resolution_clock::now();
}

Timer::~Timer() {
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	float result = duration.count();
	std::cout << result << " second";
}
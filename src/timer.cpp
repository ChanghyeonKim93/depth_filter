#include "timer.h"
#include "common.h"
auto ti = std::chrono::high_resolution_clock::now();
auto t1 = ti;

unsigned long tic(){
	auto tf = std::chrono::high_resolution_clock::now();
	auto ticks = std::chrono::duration_cast<std::chrono::microseconds>(tf - ti);

	return (unsigned long)ticks.count();
}

unsigned long toc(){
	auto tf = std::chrono::high_resolution_clock::now();
	auto ticks = std::chrono::duration_cast<std::chrono::microseconds>(tf - t1);
	t1 = tf;

	return (unsigned long)ticks.count();
}


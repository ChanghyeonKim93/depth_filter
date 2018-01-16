#include <iostream>
#include "common.h"
#include "timer.h"
#include "depth_filter.h"

int main(void){
	unsigned long ti,tf;
	Seed *seed = new Seed(10,10,1,3);
	DepthFilter *depth_filter = new DepthFilter();

	// read X

	// for loop
	ti = tic();
	for(int m=0;m<500;m++){
		depth_filter->updateSeed(2.0,0.6,seed);
		//std::cout<<m<<std::endl;
		//std::cout<<"mu : "<<seed->mu<<", sigma : "<<seed->sigma<<", pi : "<<seed->a/(seed->a+seed->b)<<std::endl;
	}
	tf = toc();
	std::cout<<"Elapsed time : "<<tf/1000000.0<<std::endl;


	return 0;
}

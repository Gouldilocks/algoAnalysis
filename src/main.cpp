//
// Created by christian on 3/16/21.
//
#include <iostream>
#include "AlgoRunner.h"
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
int main(int argc, char** argv){
	AlgoRunner runMe;
	// generate Data
	if(argc == 1){
		runMe.generateData (6);
	}
	// run the program
	else {
	// run with the output file name as only parameter
		runMe.execute(argv[1]);
	}
	return 0;
}

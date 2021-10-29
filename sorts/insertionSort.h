//
// Created by loggityloglog on 10/12/20.
//

#ifndef INC_20F_SORT_INSERTIONSORT_H
#define INC_20F_SORT_INSERTIONSORT_H
#include "AlgorithmStrategy.h"
class insertionSort : public AlgorithmStrategy {
public:
	insertionSort() : AlgorithmStrategy() {this->algoType = 'i';}
	// overrides the Execute function in parent class
	float Execute ();
	// implements insertionSort itself
	void sortIt(int *numbers, int numbersSize);
};

#endif //INC_20F_SORT_INSERTIONSORT_H

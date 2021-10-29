//
// Created by loggityloglog on 10/12/20.
//

#ifndef INC_20F_SORT_MERGESORT_H
#define INC_20F_SORT_MERGESORT_H
#define use_handoff_to_selection true
#include "AlgorithmStrategy.h"
class mergeSort :public AlgorithmStrategy {
public:
	mergeSort() : AlgorithmStrategy() {this->algoType = 'm';}
	float Execute ();
	void merge(int numbers[], int i, int j, int k);
	void sortIt(int *numbers, int i, int k);
};
#endif //INC_20F_SORT_MERGESORT_H

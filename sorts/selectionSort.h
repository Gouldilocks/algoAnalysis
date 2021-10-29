//
// Created by loggityloglog on 10/12/20.
//

#ifndef INC_20F_SORT_SELECTIONSORT_H
#define INC_20F_SORT_SELECTIONSORT_H
#include "AlgorithmStrategy.h"
class selectionSort :public AlgorithmStrategy {
public:
	selectionSort() : AlgorithmStrategy() {this->algoType = 's';}
	float Execute ();
	void SelectionSort (int numbers[], int numbersSize);
};
#endif //INC_20F_SORT_SELECTIONSORT_H

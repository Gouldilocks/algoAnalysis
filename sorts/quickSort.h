//
// Created by Chrisitan Gould on 10/12/20.
//

#ifndef INC_20F_SORT_QUICKSORT_H
#define INC_20F_SORT_QUICKSORT_H
#define use_handoff_to_selection true
#include "AlgorithmStrategy.h"
using namespace std;
class quickSort : public AlgorithmStrategy{
public:
	quickSort() : AlgorithmStrategy() {this->algoType = 'q';}
	float Execute ();
	int partition(int *numbers, int i, int k);
	void Quicksort(int numbers[], int i, int k);
};
#endif //INC_20F_SORT_QUICKSORT_H

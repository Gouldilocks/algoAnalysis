//
// Created by christian on 3/16/21.
//

#ifndef INC_21S_PA02_GOULDILOCKS_CYCLESORT_H
#define INC_21S_PA02_GOULDILOCKS_CYCLESORT_H

#include <AlgorithmStrategy.h>
#include <AlgoRunner.h>
class cycleSort : public AlgorithmStrategy {
public:
	cycleSort() : AlgorithmStrategy(){this->algoType = 'b';}
	float Execute();
	void CycleSort(int *arr, int n);
};


#endif //INC_21S_PA02_GOULDILOCKS_CYCLESORT_H

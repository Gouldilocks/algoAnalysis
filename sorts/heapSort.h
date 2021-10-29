//
// Created by christian on 3/16/21.
//

#ifndef INC_21S_PA02_GOULDILOCKS_HEAPSORT_H
#define INC_21S_PA02_GOULDILOCKS_HEAPSORT_H

#include <AlgorithmStrategy.h>
#include <AlgoRunner.h>
class heapSort : public AlgorithmStrategy {
public:
heapSort() : AlgorithmStrategy() {this->algoType = 'h';}
float Execute();
void heapify(int arr[], int n, int i);
void HeapSort(int*, int);
};


#endif //INC_21S_PA02_GOULDILOCKS_HEAPSORT_H

//
// Created by christian on 3/9/21.
//

#ifndef INC_21S_PA02_GOULDILOCKS_ALGORUNNER_H
#define INC_21S_PA02_GOULDILOCKS_ALGORUNNER_H
#include <AlgorithmStrategy.h>
#include <vector>
#include <iostream>
#include <insertionSort.h>
#include <mergeSort.h>
#include <quickSort.h>
#include <selectionSort.h>
using namespace std;
class AlgoRunner {
public:
	/* Constructors */
	AlgoRunner();
	/* Destructor */
	~AlgoRunner();
	/* Functions */
	void execute(char* outputName);
	void generateData (int numDataSets);
	// randomizes a given array to the percent given. Default is 100%
	void randomize_Array(int* randomizeMe, int sizeOfArray, double randomnessPercent = 100);
	void outputFileType(ofstream&, int fileNum) const;
	void coutFileType(int fileNum) const;
	/* Operators */
private:
	vector<AlgorithmStrategy*> sortingAlgos;
};


#endif //INC_21S_PA02_GOULDILOCKS_ALGORUNNER_H

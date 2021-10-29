//
// Created by loggityloglog on 10/12/20.
//
// referenced Professor Gabrielson's lecture materials for insertion Execute implementation
#include "insertionSort.h"
float insertionSort ::Execute () {
	if(size == 1000000)
		return -1;
	// copy the dataset into a new array
	int dataSet[size];
	for(int i = 0; i < size; i++){
		dataSet[i] = data[i];
	}
	// return the time of execution
	auto start = high_resolution_clock::now();
	sortIt(dataSet,size);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	float returnMe = duration.count();
	// convert to seconds
	this->runTime = returnMe/ 1000000;
	return runTime;
}
void insertionSort:: sortIt(int *numbers, int numbersSize) {
	int i;
	int j;
	int temp;      // Temporary variable for swap

	for (i = 1; i < numbersSize; ++i) {
		j = i;
		// Insert numbers[i] into sorted part
		// stopping once numbers[i] in correct position
		while (j > 0 && numbers[j] < numbers[j - 1]) {

			// Swap numbers[j] and numbers[j - 1]
			temp = numbers[j];
			numbers[j] = numbers[j - 1];
			numbers[j - 1] = temp;
			--j;
		}
	}
	}

//
// Created by Christian Gould on 10/12/20.
//
// selection Execute adapted from professor gabrielson's lecture materials
#include "selectionSort.h"

float selectionSort::Execute () {
	if(size == 1000000)
		return -1;
	// copy the dataset
	int dataSet[size];
	for(int i = 0; i < size; i++){
		dataSet[i] = data[i];
	}

	// calculate the run time
	auto start = high_resolution_clock::now();
	SelectionSort(dataSet,size);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	float returnMe = duration.count();
	// convert to seconds
	this->runTime = returnMe/ 1000000;
	return runTime;
}

void selectionSort::SelectionSort (int *numbers, int numbersSize) {
	int i;
	int j;
	int indexSmallest;
	int temp;      // Temporary variable for swap

	for (i = 0; i < numbersSize - 1; ++i) {

		// Find index of smallest remaining element
		indexSmallest = i;
		for (j = i + 1; j < numbersSize; ++j) {
				// comparing numbers[j] to numbers[indexSmallest]
			if ( numbers[j] < numbers[indexSmallest] ) {
				indexSmallest = j;
			}
		}

		// Swap numbers[i] and numbers[indexSmallest]
		temp = numbers[i];
		numbers[i] = numbers[indexSmallest];
		numbers[indexSmallest] = temp;
	}
}


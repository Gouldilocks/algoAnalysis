//
// Created by Christian Gould on 10/12/20.
//
// merge Execute implementation taken and adapted from Professor Gabrielson's lecture materials
#include "mergeSort.h"

float mergeSort::Execute () {
	// copy the dataset
	int dataSet[size];
	for(int i = 0; i < size; i++){
		dataSet[i] = data[i];
	}
	// calculate the time for execution
	auto start = high_resolution_clock::now();
	sortIt(dataSet,0,size-1);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	float returnMe = duration.count();
	this->runTime = returnMe/ 1000000;
	return runTime;
}

void mergeSort:: merge (int *numbers, int i, int j, int k) {
		int mergedSize;                            // Size of merged partition
		int mergePos;                              // Position to insert merged number
		int leftPos;                               // Position of elements in left partition
		int rightPos;                              // Position of elements in right partition
		int* mergedNumbers = nullptr;

		mergePos = 0;
		mergedSize = k - i + 1;
		leftPos = i;                               // Initialize left partition position
		rightPos = j + 1;                          // Initialize right partition position
		mergedNumbers = new int[mergedSize];       // Dynamically allocates temporary array
		// for merged numbers

		// Add smallest element from left or right partition to merged numbers
		// while loop comparisons not counted because they are counter comparisons
		while (leftPos <= j && rightPos <= k) {
			// the comparisons are too many at this point to be considered usable
			// increase comparisons because of the if statement below
			if (numbers[leftPos] < numbers[rightPos]) {
				mergedNumbers[mergePos] = numbers[leftPos];
				++leftPos;
			}
			else {
				mergedNumbers[mergePos] = numbers[rightPos];
				++rightPos;

			}
			++mergePos;
		}

		// If left partition is not empty, add remaining elements to merged numbers
		while (leftPos <= j) {
			mergedNumbers[mergePos] = numbers[leftPos];
			++leftPos;
			++mergePos;
		}

		// If right partition is not empty, add remaining elements to merged numbers
		while (rightPos <= k) {
			mergedNumbers[mergePos] = numbers[rightPos];
			++rightPos;
			++mergePos;
		}

		// Copy merge number back to numbers
		for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
			numbers[i + mergePos] = mergedNumbers[mergePos];
		}
		delete[] mergedNumbers;
}
void mergeSort :: sortIt(int *numbers, int i, int k) {
	int j;

	if (i < k) {

		// when there are 10 elements or less, use selection sort as a handoff
		if(use_handoff_to_selection) if(k-i <= 10){
				this->Handoff('i',i,k,numbers);
				return;
			}

		j = (i + k) / 2;  // Find the midpoint in the partition

		// Recursively Execute left and right partitions
		sortIt(numbers, i, j);
		sortIt(numbers, j + 1, k);
		// Merge left and right partition in sorted order
	}
}

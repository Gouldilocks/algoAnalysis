//
// Created by christian on 3/16/21.
//
/*
 * Implementation of cycle Sort taken directly from:
 * https://www.geeksforgeeks.org/cycle-sort/
 */
#include <algorithm>
#include "cycleSort.h"

float cycleSort::Execute () {
	/*
	 * this is a check for cyclesort, because running 1 mil on this
	 * sorting algo does not end well, taking about 17 minutes to finish
	 * one dataset. This stops the run from happening.
	 */
	if(size == 1000000)
		return -1;
// copy the dataset in float form
	int dataSet[size];
	for(int i = 0; i < size; i++){
		dataSet[i] = data[i];
	}
	// calculate the run time
	auto start = high_resolution_clock::now();
	CycleSort (dataSet, size);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	float returnMe = duration.count();
	// convert to seconds
	this->runTime = returnMe/ 1000000;
	return runTime;
}

// Function to sort arr[] of
// size n using bucket sort
void cycleSort::CycleSort(int arr[], int n)
{
	// count number of memory writes
	int writes = 0;

	// traverse array elements and put it to on
	// the right place
	for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
		// initialize item as starting point
		int item = arr[cycle_start];

		// Find position where we put the item. We basically
		// count all smaller elements on right side of item.
		int pos = cycle_start;
		for (int i = cycle_start + 1; i < n; i++)
			if (arr[i] < item)
				pos++;

		// If item is already in correct position
		if (pos == cycle_start)
			continue;

		// ignore all duplicate  elements
		while (item == arr[pos])
			pos += 1;

		// put the item to it's right position
		if (pos != cycle_start) {
			swap(item, arr[pos]);
			writes++;
		}

		// Rotate rest of the cycle
		while (pos != cycle_start) {
			pos = cycle_start;

			// Find position where we put the element
			for (int i = cycle_start + 1; i < n; i++)
				if (arr[i] < item)
					pos += 1;

			// ignore all duplicate  elements
			while (item == arr[pos])
				pos += 1;

			// put the item to it's right position
			if (item != arr[pos]) {
				swap(item, arr[pos]);
				writes++;
			}
		}
	}

	// Number of memory writes or swaps
	// cout << writes << endl ;
}
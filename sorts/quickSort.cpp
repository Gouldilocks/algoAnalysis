//
// Created by Christian Gould on 10/12/20.
//
// quicksort adapted from professor gabrielsen's lecture notes
#include "quickSort.h"
float quickSort::Execute () {
	// copy the dataset
	int dataSet[size];
	for(int i = 0; i < size; i++){
		dataSet[i] = data[i];
	}
	auto start = high_resolution_clock::now();
	Quicksort(dataSet,0,size-1);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	float returnMe = duration.count();
	// convert to seconds
	this->runTime = returnMe/ 1000000;
	return runTime;
}
int quickSort::partition (int *numbers, int i, int k) {
	int l;
	int h;
	int midpoint;
	int pivot;
	int temp;
	bool done;

	/* Pick middle element as pivot */
	midpoint = i + (k - i) / 2;
	pivot = numbers[midpoint];

	done = false;
	l = i;
	h = k;

	while (!done) {

		/* Increment l while numbers[l] < pivot */
		while (numbers[l] < pivot) {
			++l;
		}

		/* Decrement h while pivot < numbers[h] */
		while (pivot < numbers[h]) {
			--h;
		}

		/* If there are zero or one elements remaining,
		 all numbers are partitioned. Return h */
		if (l >= h) {
			done = true;
		}
		else {
			/* Swap numbers[l] and numbers[h],
			 update l and h */
			temp = numbers[l];
			numbers[l] = numbers[h];
			numbers[h] = temp;

			++l;
			--h;
		}
	}

	return h;
	}

void quickSort::Quicksort (int *numbers, int i, int k) {
	int j;

	/* Base case: If there are 1 or zero elements to sort,
	 partition is already sorted */
	if (i >= k) {
		return;
	}

	// when there are 10 elements or less, use selection sort as a handoff
	if(use_handoff_to_selection) if(k-i <= 10){
		this->Handoff('i',i,k,numbers);
		return;
	}
	/* Partition the data within the array. Value j returned
	 from partitioning is location of last element in low partition. */
	j = partition(numbers, i, k);

	/* Recursively sort low partition (i to j) and
	 high partition (j + 1 to k) */
	Quicksort(numbers, i, j);
	Quicksort(numbers, j + 1, k);
}


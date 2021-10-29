//
// Created by christian on 3/16/21.
//
/*
 * Heapsort implementation taken directly from:
 * https://www.geeksforgeeks.org/heap-sort/
 */
#include "heapSort.h"

float heapSort::Execute () {
// copy the dataset into a new array
	int dataSet[size];
	for(int i = 0; i < size; i++){
		dataSet[i] = data[i];
	}
	auto start = high_resolution_clock::now();
	HeapSort(dataSet,size);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	float returnMe = duration.count();
	// convert to seconds
	this->runTime = returnMe/ 1000000;
	return runTime;
}
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapSort::heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort::HeapSort(int *arr, int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}
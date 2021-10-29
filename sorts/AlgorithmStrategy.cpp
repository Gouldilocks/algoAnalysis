//
// Created by Christian Gould on 10/12/20.
//
#include "AlgorithmStrategy.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "heapSort.h"
#include "cycleSort.h"
#include <iostream>
#include <cmath>
#define debug false

void AlgorithmStrategy::Handoff (char toHand, int begin, int end, int *dataSet) {
switch(toHand){
	// insertion sort
	case 'i':{
		insertionSort hand;
		// sort the part of the array from the beginning to the end
		hand.sortIt(dataSet+begin,end-begin);
		break;
	}

	// merge sort
	case 'm':{
		mergeSort hand;
		hand.sortIt(dataSet,begin,end);
		break;
	}

	// quick sort
	case 'q':{
		quickSort hand;
		hand.Quicksort(dataSet,begin,end);
		break;
	}

	// selection sort
	case 's':{
		selectionSort hand;
		hand.SelectionSort(dataSet+begin,end-begin);
		break;
	}
	// heap sort
	case 'h':{
		heapSort hand;
		hand.HeapSort(dataSet+begin, end-begin);
		break;
	}
	case 'b':{
		cycleSort hand;
		hand.CycleSort (dataSet + begin, end - begin);
	}
}
}

void AlgorithmStrategy::Load (int *data, int size) {
// make a shallow copy, because deep copy is made in each implementation of the sort.
this->data = data;
this->size = size;
this->runTime = 0;
}

AlgorithmStrategy::AlgorithmStrategy () {
data = nullptr;
size = 0;
runTime = 0;
algoType = '0';
}

AlgorithmStrategy::AlgorithmStrategy (const AlgorithmStrategy &copyMe) {
this-> size = copyMe.size;
this->runTime = copyMe.runTime;
this->data = new int[size];
this->algoType = copyMe.algoType;
for(int i = 0; i < size; ++i)
	this->data[i] = copyMe.data[i];
}


void AlgorithmStrategy::Stats () {
	string returnMe;
cout << "Algorithm: " << getAlgorithm() << " Execution time: " << runTime << " Number of records: " << size << endl;
}

string AlgorithmStrategy::getAlgorithm () const {
	string algo;
	switch(algoType) {
		case 'i': {
			algo = "Insertion Sort";
			break;
		}
		case 'm': {
			algo = "Merge Sort";
			break;
		}
		case 'q': {
			algo = "Quick Sort";
			break;
		}
		case 's': {
			algo = "Selection Sort";
			break;
		}
		case 'h': {
			algo = "Heap Sort";
			break;
		}
		case 'b': {
			algo = "Cycle Sort";
			break;
		}
	}
	return algo;
}

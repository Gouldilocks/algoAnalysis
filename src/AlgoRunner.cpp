//
// Created by christian on 3/9/21.
//

#include "AlgoRunner.h"
#include <math.h>
#include <sstream>
#include <stack>
#include <heapSort.h>
#include <cycleSort.h>

using namespace std;
#define debug false

void AlgoRunner::execute (char *outputName) {
	// set up the output file and its header line
	ofstream output;
	output.open (outputName);
	cout << "Algorithm,DataSetType,DataSetSize,ExecutionTime" << endl;

	// set up the input files as pointers to be put into vector
	auto* random = new ifstream();
	random->open ("datasets/RandomData.txt");
	auto* reversed = new ifstream();
	reversed->open ("datasets/ReversedData.txt");
	auto* thirty = new ifstream();
	thirty->open ("datasets/ThirtyPercent.txt");
	auto* twenty = new ifstream();
	twenty->open ("datasets/TwentyPercent.txt");

	// put the input files into a vector in order to iterate over them.
	vector<ifstream*> files;
	files.push_back (random);
	files.push_back (reversed);
	files.push_back (thirty);
	files.push_back (twenty);



	// execute each sort on all datasets

		// for each data set size
		for (int i = 0; i < 6; ++i) {
			// calc the size of the dataset
			int dataSize = pow(10,i+1);
			// for each of the files
			for (int fileNum = 0; fileNum < 4; fileNum++) {
				coutFileType(fileNum);
				// set the dataset
				int* dataSet = new int[dataSize];

				// get the data of one line and tokenize it into dataSet
				// input buffer
				string buffer;
					// get the full line of data
					while (getline (*files.at(fileNum), buffer)) {
						buffer = "";
						// create a string stream in order to tokenize
						stringstream ss (buffer);
						// tokenize the whole line to get each piece of data
						int dataSetIndex = 0;
						while (getline (ss, buffer, ',')) {
							// get each of the data pieces and convert to int
							dataSet[dataSetIndex] = stoi(buffer);
							dataSetIndex++;
						}
					}
				// execute the sort on all the algorithms for this dataset size
					// for each of the sorting Algos
					for (auto &algo : sortingAlgos) {
						//load the data, execute the sort and print stats
						algo->Load(dataSet,dataSize);
						float e_time = algo->Execute ();
						algo->Stats();

						// output to the file
						output << algo->getAlgorithm() << ",";
						outputFileType(output, fileNum);
						output << dataSize << ",";
						output << e_time << endl;

					}
				// delete the dataset array
				delete[] dataSet;
			}

		}
}

AlgoRunner::AlgoRunner () {
	sortingAlgos.push_back (new mergeSort ());
	sortingAlgos.push_back (new quickSort ());
	sortingAlgos.push_back (new heapSort());
	sortingAlgos.push_back (new cycleSort());
	sortingAlgos.push_back (new selectionSort ());
	sortingAlgos.push_back (new insertionSort ());
}

void AlgoRunner::generateData (int numDataSets) {
	auto *randomDataSets = new vector<int *> ();
	auto *reversedOrderSets = new vector<int *> ();
	auto *twentyPerUniSets = new vector<int *> ();
	auto *thirtyPerRandSets = new vector<int *> ();
	vector<int> dataSetSizes;

	// will loop numdatasets times, and will make 3 variations of the dataset each time it loops
	for (int d = 0; d < numDataSets; d++) {

		if (debug)cout << "generating set #" << d;

		// seed the random number for the shuffle portion
		srand ((unsigned) time (0) * d);

		// increment the size by an exponent of the number of datasets made already
		int size = pow (10, d + 1);

		// push back the size of all the datasets at this index of all the vectors
		dataSetSizes.push_back (size);

		if (debug) cout << " of size: " << size << endl;


		// generate the random list and push it back to the vector
		int *randomSet = new int[size];
		for (int i = 0; i < size; i++) {
			randomSet[ i ] = i;
		}
		randomize_Array (randomSet, size);
		randomDataSets->push_back (randomSet);


		// make the reverse dataset and push it back to the vector
		int *reverseSet = new int[size];
		for (int i = size, j = 0; i > 0 && j < size; --i, ++j) {
			reverseSet[ j ] = i;
		}
		reversedOrderSets->push_back (reverseSet);


		// generate the 20% unique value sets and push it back to the vector
		int *twentyUnique = new int[size];
		int numUnique = size / 5;
		for (int i = 0, j = 0; i < size; i++, j++) {
			twentyUnique[ i ] = j;
			if (j == numUnique - 1) j = 0;
		}
		randomize_Array (twentyUnique, size);
		twentyPerUniSets->push_back (twentyUnique);


		// generate the 30% randomized list and push it back to the vector
		int *thirtyRandom = new int[size];
		for (int i = 0; i < size; i++) {
			thirtyRandom[ i ] = i;
		}
		randomize_Array (thirtyRandom, size, 30);
		thirtyPerRandSets->push_back (thirtyRandom);

	}
	// end data generation

	// start data generation filing

	// output all data for the random data sets
	ofstream randomSets;
	randomSets.open ("RandomData.txt");
	for (int i = 0; i < randomDataSets->size (); i++) {
		randomSets << randomDataSets->at (i)[ 0 ];
		for (int at = 1; at < dataSetSizes[ i ]; at++) {
			randomSets << "," << randomDataSets->at (i)[ at ];
		}
		randomSets << endl;
	}
	randomSets.close ();


	// output all data for the reversed order sets
	ofstream reversedSets;
	reversedSets.open ("ReversedData.txt");
	for (int i = 0; i < reversedOrderSets->size (); i++) {
		reversedSets << reversedOrderSets->at (i)[ 0 ];
		for (int at = 1; at < dataSetSizes[ i ]; at++) {
			reversedSets << "," << reversedOrderSets->at (i)[ at ];
		}
		reversedSets << endl;
	}
	reversedSets.close ();


	// output all data for the twenty percent unique sets
	ofstream twentyPercent;
	twentyPercent.open ("TwentyPercent.txt");
	for (int i = 0; i < twentyPerUniSets->size (); i++) {
		twentyPercent << twentyPerUniSets->at (i)[ 0 ];
		for (int at = 1; at < dataSetSizes[ i ]; at++) {
			twentyPercent << "," << twentyPerUniSets->at (i)[ at ];
		}
		twentyPercent << endl;
	}
	twentyPercent.close ();


	// output all data for the thirty percent random sets
	ofstream thirtyPercent;
	thirtyPercent.open ("ThirtyPercent.txt");
	for (int i = 0; i < thirtyPerRandSets->size (); i++) {
		thirtyPercent << thirtyPerRandSets->at (i)[ 0 ];
		for (int at = 1; at < dataSetSizes[ i ]; at++) {
			thirtyPercent << "," << thirtyPerRandSets->at (i)[ at ];
		}
		thirtyPercent << endl;
	}
	thirtyPercent.close ();
}

void AlgoRunner::randomize_Array (int *randomizeMe, int sizeOfArray, double randomnessLevel) {

	// if the randomness level is default, then make it VERY random. Otherwise use randomnessLevel as a percentage of the size
	double stopAt = (randomnessLevel == 100) ? 10 * randomnessLevel * (double) sizeOfArray : (double) sizeOfArray *
	                                                                                         (randomnessLevel / 100);

	// make the randomized dataset
	for (int i = 0; i < (int) stopAt; i++) {

		// generate random indexes to swap
		int r1 = (rand () % sizeOfArray - 1);
		int r2 = (rand () % sizeOfArray - 1);
		int temp;

		// swap the two elements
		temp = randomizeMe[ r1 ];
		randomizeMe[ r1 ] = randomizeMe[ r2 ];
		randomizeMe[ r2 ] = temp;
	}
}

AlgoRunner::~AlgoRunner () {
	// delete each of the sorting algos
	for(int i = 0; i < sortingAlgos.size(); i++){
		delete sortingAlgos.at(i);
	}
}

void AlgoRunner::outputFileType (ofstream &o, int fileNum) const{
	switch (fileNum) {
		case 0:{
			o<< "RandomData,";
			break;
		}
		case 1:{
			o<< "ReversedData,";
			break;
		}
		case 2:{
			o<<"ThirtyPercent,";
			break;
		}
		case 3:{
			o<<"TwentyPercent,";
			break;
		}
	}
}

void AlgoRunner::coutFileType (int fileNum) const{
	cout << endl;
	switch (fileNum) {
		case 0:{
			cout<< "RandomData: ";
			break;
		}
		case 1:{
			cout<< "ReversedData: ";
			break;
		}
		case 2:{
			cout<<"ThirtyPercent: ";
			break;
		}
		case 3:{
			cout<<"TwentyPercent: ";
			break;
		}
	}
	cout << endl;
}

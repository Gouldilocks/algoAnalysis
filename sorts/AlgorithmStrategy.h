//
// Created by loggityloglog on 10/12/20.
//

#ifndef INC_20F_SORT_ALGOANALYSER_H
#define INC_20F_SORT_ALGOANALYSER_H
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <chrono>
using namespace std::chrono;
using namespace std;
class AlgorithmStrategy {
public:
	/* constructors */
	// default constructor
	AlgorithmStrategy();
	// copy constructor
	AlgorithmStrategy(const AlgorithmStrategy& copyMe);
	/* destructor */
	~AlgorithmStrategy() = default;
	/* functions */
	/**
	 * Takes a filename and can read input data file. See README for information about format for input file
	 * @param fileName - the name of the file which holds the dataset
	 */
	void Load(int* data, int size);
	/**
	 * Prints algorithm name, execution time, and number of records analyzed to screen in a readable format
	 */
	void Stats();
	/**
	 * similar to Select(string input) , but indicates what algorithm to handoff sorting to and at what data set size
	 * @param toHand - indicates which algorithm to hand off to
	 * @param size - indicates the size at which to hand off the sorting to another algorithm
	 * @returns the time which it took to run the handoff
	 */
	void Handoff (char toHand, int begin, int end, int *dataSet);
	/**
	 * Executes the search algorithm
	 */
	virtual float Execute () = 0;
	string getAlgorithm() const;
protected:
	int* data;
	int size;
	// runTime in microseconds
	double runTime;
	char algoType;
};

#endif //INC_20F_SORT_ALGOANALYSER_H

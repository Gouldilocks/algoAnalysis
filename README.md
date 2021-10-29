# Project 2 - Sorting Analysis


## What is this?
Hello! This is the repository for Project 2 in CS3353. This project's purpose is to gather data about sorting algorithms. Specifically, about Quicksort, Mergesort, Selectionsort, Insertionsort, Heapsort, and Cyclesort.


## Great, How do I use the thing??
Glad you asked! The only input needed for this program, is to pass the intended name for the output file as a parameter to the program. There are no dependencies which need to be installed in order to run the program. The program only uses the standard library for all processes. 

If you would like to create new data files, you may do so by simply passing no arguments to the program when you run it. After doing so, place each of the dataset files into the "datasets" directory, and then run the program again, this time passing the output file name, as stated above.


## Output format and details
The output is in .CSV format, and is organized as follows: "SortingAlgo,Datatype,DataSetSize,ExecutionTime". Ex.)

```
Merge Sort,ReversedData,100,1e-06
Quick Sort,ReversedData,100,4e-06
Heap Sort,ReversedData,100,1.1e-05
Cycle Sort,ReversedData,100,3.6e-05
Selection Sort,ReversedData,100,1.2e-05
```

## Implementation details
This project was implemented using polymorphism, and using the std::chrono library.


### Polymorphic Implementation
The project included the use of a parent class, called "AlgorithmStrategy", which can be found in: "sorts/AlgorithmStrategy.h". The class is a parent class to each of the sorting algorithms implemented in the sorts directory. In the driver class, each of these sorting algorithms is added to a vector of AlgorithmStrategy pointers, and after loading the generated data, calls the Execute() function. Execute() is a pure virtual function, which starts the sort on the loaded dataset in that particular child sorting algorithm.

### Std::chrono library use
The std::chrono library is used in order to time each of the sorting algorithm's execution time. A high_resolution_clock object is used in order to get the time taken for the sort to complete. The result of which is stored in a float as milliseconds, and then converted to seconds.

## What have we learned?
A more in-depth report is in the analysis directory, as a .docx formatted paper, named "[findings.docx](https://github.com/smu-cs-3353/21s-pa02-Gouldilocks/blob/main/analysis/findings.docx)", and all data used is in "[SortingData.xlsx](https://github.com/smu-cs-3353/21s-pa02-Gouldilocks/blob/main/analysis/SortingData.xlsx)", which has two pages, one with graphs, and the other with charts. I have also added an output file in the "analysis" folder, nammed "[runner.csv](https://github.com/smu-cs-3353/21s-pa02-Gouldilocks/blob/main/analysis/runner.csv)". 

Overall, the findings were not super surprising, with overall, the fastest algorithm tending to be merge sort over quicksort. One thing to think about when talking about that, however, is that quicksort sorts in place, as mergesort requires another whole array of like size to the original to be made. This means that quicksort makes a small sacrifice in speed/consistency in order to allow itself to be much more memory efficient.

![allsorts](https://github.com/smu-cs-3353/21s-pa02-Gouldilocks/blob/main/artifacts/allSortsZoomed.png)

In the chart above, it is clear that insertion sort, selection sort, and cycle sort are not holding up to their more powerful, O(nlg(n)) brothers. However, it is interesting that there is such deviation between the three. This graph is very zoomed in, but it is clear that the difference would be that of a constant value, and thus gets absorbed into O(n^2) for these three algorithms. Below them, you can see that there is a similar type of difference between heap sort, quicksort, and merge sort. It is to be noted however, that both merge sort and quick sort in this graph, have been implemented with a handoff to selection sort when the partition has 10 or less elements. This choice of selection sort becomes obviously a misstep with further data that was gathered later.

![MergeSortPic](https://github.com/smu-cs-3353/21s-pa02-Gouldilocks/blob/main/artifacts/MsortHandoff.png)
![QuickSortPic](https://github.com/smu-cs-3353/21s-pa02-Gouldilocks/blob/main/artifacts/QsortHandoff.png)

Now above, you can see that in both merge sort, and quick sort, that there is a problem with having selection sort as a hand off. Both merge sort and quicksort become slower with a <=10 element handoff, and even slower than that with <=100 element handoff. However, once we switch over to Insertion sort, it becomes clear that it is useful to do handoffs, because once we hand off at 10 elements to insertion sort, it becomes slightly quicker than the original in both algorithms! This was an awesome discovery, as it was getting a little bit hopeless, as I saw selection sort make both quicksort and merge sort slower as a result of adding a handoff. More information about all of this can be found in [the report](https://github.com/smu-cs-3353/21s-pa02-Gouldilocks/blob/main/analysis/findings.docx).

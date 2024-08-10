#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
using namespace std::chrono;

#include "ioFunctions.h"
#include "IntroSort.h"
#include "BlockSort.h"
#include "CubeSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "CountingSort.h"
#include "RadixSort.h"

int main() {
	// for each (size, max) of dataset, we will do test on 3 distribution (totally random, forward distributed, backward distributed), 
	// 2 dataset each distribution, 5 times each dataset
	// we have 9 sorting algorithms, each algorithm on each dataset will be tested 5 times
	int size = 100000, max = 1000000;
	vector<vector<int>> results(9, vector<int>(30, -1));
	// (size, max) = { (1000, 100000), (10000, 1000000), (100000, 1000000) }
	// when testing on size > 2000, we will skip the quicksort due to crashing

	for (int distribution = 0; distribution < 3; ++distribution) {
		for (int dataset = 1; dataset <= 2; ++dataset) {
			for (int times = 1; times <= 5; ++times) {
				std::string testName, sortName;
				switch (distribution)
				{
				case 0:
					testName = std::to_string(size) + "random" + std::to_string(max) + "_" + std::to_string(dataset) + ".txt";
					break;
				case 1:
					testName = std::to_string(size) + "forward" + std::to_string(max) + "_" + std::to_string(dataset) + ".txt";
					break;
				case 2:
					testName = std::to_string(size) + "backward" + std::to_string(max) + "_" + std::to_string(dataset) + ".txt";
					break;
				default:
					break;
				}

				for (int sortAlg = 0; sortAlg < 9; ++sortAlg) {
					vector<int> testArr;
					loadArray(testName, testArr, size);

					auto start = high_resolution_clock::now();

					// doing test
					switch (sortAlg)
					{
					case 0:
						sortName = "introSort";
						testArr = introSort(testArr);
						break;
					case 1:
						sortName = "blockSort";
						testArr = blockSort(testArr);
						break;
					case 2:
						sortName = "cubeSort";
						testArr = cubeSort(testArr);
						break;
					case 3:
						sortName = "selectionSort";
						testArr = selectionSort(testArr);
						break;
					case 4:
						sortName = "insertionSort";
						testArr = insertionSort(testArr);
						break;
					case 5:
						sortName = "quickSort";
						if (size < 2000) {
							testArr = quickSort(testArr);
						}
						break;
					case 6:
						sortName = "mergeSort";
						testArr = mergeSort(testArr);
						break;
					case 7:
						sortName = "countingSort";
						testArr = countingSort(testArr);
						break;
					case 8:
						sortName = "radixSort";
						testArr = radixSort(testArr);
						break;
					default:
						break;
					}

					auto stop = high_resolution_clock::now();

					auto duration = duration_cast<microseconds>(stop - start);

					std::cout << "----------------------------------------" << endl;
					std::cout << testName << " with " << sortName << endl;
					std::cout << "Time taken: " << duration.count() << " microseconds" << endl;

					results[sortAlg][distribution * 10 + (dataset - 1) * 5 + times - 1] = duration.count();
					saveArray(sortName, times, testName, testArr);
				}
			}
		}

	}

	saveResults(results, size, max);

	//vector<int> testArr;
	//ifstream input("../dataset/test2.txt");
	//if (input.good())
	//	loadArray(input, testArr, 10000);
	//input.close();

	//auto start = high_resolution_clock::now();

	//testArr = selectionSort(testArr);

	//auto stop = high_resolution_clock::now();

	//auto duration = duration_cast<microseconds>(stop - start);

	//cout << "Time taken: "
	//	<< duration.count() << " microseconds" << endl;
	//ofstream output("selectionSortReport.txt");
	//if (output.good())
	//	saveArray(output, testArr);
	//output.close();

	return 0;
}
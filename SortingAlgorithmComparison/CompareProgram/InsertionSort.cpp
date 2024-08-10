#include "InsertionSort.h"

std::vector<int> insertionSort(std::vector<int>& numArr) {
	int size = numArr.size();
	for (int i = 0; i < size; ++i) {
		int key = numArr[i], j = i - 1;
		while (j >= 0 && numArr[j] > key) {
			numArr[j + 1] = numArr[j];
			--j;
		}
		numArr[j + 1] = key;
	}

	return numArr;
}
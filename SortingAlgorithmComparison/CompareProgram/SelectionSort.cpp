#include "SelectionSort.h"

std::vector<int> selectionSort(std::vector<int>& numArr) {
	int size = numArr.size();
	for (int i = 0; i < size - 1; ++i) {
		int minIndex = i + 1;
		int min = numArr[minIndex];

		for (int j = i + 2; j < size; ++j)
			if (numArr[j] < min) {
				minIndex = j;
				min = numArr[j];
			}

		std::swap(numArr[i], numArr[minIndex]);
	}

	return numArr;
}
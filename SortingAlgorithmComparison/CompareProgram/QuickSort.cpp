#include "QuickSort.h"

int partition(std::vector<int>& numArr, int low, int high) {
	int pivot = numArr[high];
	
	int i = low - 1;

	for (int j = low; j < high; ++j) {
		if (numArr[j] < pivot) {
			++i;
			std::swap(numArr[i], numArr[j]);
		}
	}
	std::swap(numArr[i + 1], numArr[high]);
	return (i + 1);
}

void quickSort(std::vector<int>& numArr, int low, int high) {
	if (low >= high)
		return;

	int partitionIndex = partition(numArr, low, high);
	quickSort(numArr, low, partitionIndex - 1);
	quickSort(numArr, partitionIndex + 1, high);
}

std::vector<int> quickSort(std::vector<int>& numArr) {
	quickSort(numArr, 0, numArr.size() - 1);
	return numArr;
}

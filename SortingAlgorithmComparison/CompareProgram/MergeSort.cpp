#include "MergeSort.h"

// mid belong to the first
void merge(std::vector<int>& numArr, int begin, int mid, int end) {
	int leftLen = mid - begin + 1, rightLen = end - mid;

	std::vector<int> leftArr(numArr.begin() + begin, numArr.begin() + mid + 1), rightArr(numArr.begin() + mid + 1, numArr.begin() + end + 1);

	auto leftIt = leftArr.begin(), rightIt = rightArr.begin();
	int place = begin;
	while (leftIt != leftArr.end() && rightIt != rightArr.end()) {
		if (*leftIt < *rightIt) {
			numArr[place] = *leftIt;
			leftIt++;
		}
		else {
			numArr[place] = *rightIt;
			rightIt++;
		}
		++place;
	}

	while (leftIt != leftArr.end()) {
		numArr[place] = *leftIt;
		leftIt++;
		++place;
	}

	while (rightIt != rightArr.end()) {
		numArr[place] = *rightIt;
		rightIt++;
		++place;
	}
}

void mergeSort(std::vector<int>& numArr, int begin, int end) {
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(numArr, begin, mid);
	mergeSort(numArr, mid + 1, end);
	merge(numArr, begin, mid, end);
}

std::vector<int> mergeSort(std::vector<int>& numArr) {
	mergeSort(numArr, 0, numArr.size() - 1);
	return numArr;
}

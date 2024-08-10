#include "RadixSort.h"

//std::vector<int> countingSort(std::vector<int>& numArr, int exp) {
//	int size = numArr.size();
//	std::vector<int> countArr(10, 0);
//
//	for (int i = 0; i < size; ++i) {
//		++countArr[(numArr[i] / exp) % 10];
//	}
//
//	for (int i = 0; i < 9; ++i)
//		countArr[i + 1] += countArr[i];
//
//	std::vector<int> outputArr(size);
//
//	for (int i = size - 1; i > -1; --i) {
//		outputArr[countArr[(numArr[i] / exp) % 10] - 1] = numArr[i];
//		--countArr[(numArr[i] / exp) % 10];
//	}
//
//	return outputArr;
//}

// RadixSort implementation
std::vector<int> radixSort(std::vector<int>& numArr) {
    int n = numArr.size();
    if (n == 0) {
        return numArr;
    }
    int maxVal = *std::max_element(numArr.begin(), numArr.end());
    int exp = 1;
    while (maxVal / exp > 0) {
        // Counting sort for each digit
        std::vector<int> outputArr(n);
        std::vector<int> countArr(10, 0);
        for (int i = 0; i < n; i++) {
            int digit = (numArr[i] / exp) % 10;
            countArr[digit]++;
        }
        for (int i = 1; i < 10; i++) {
            countArr[i] += countArr[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            int digit = (numArr[i] / exp) % 10;
            outputArr[countArr[digit] - 1] = numArr[i];
            countArr[digit]--;
        }
        numArr = outputArr;
        exp *= 10;
    }
    return numArr;
}
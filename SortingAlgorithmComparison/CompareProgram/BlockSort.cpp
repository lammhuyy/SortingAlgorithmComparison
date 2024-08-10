#include "BlockSort.h"

// Insertionsort for small blocks
void insertionSortB(std::vector<int>& numArr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = numArr[i];
        int j = i - 1;
        while (j >= left && numArr[j] > key) {
            numArr[j + 1] = numArr[j];
            j--;
        }
        numArr[j + 1] = key;
    }
}

// Merge two sorted blocks
void mergeBlocks(std::vector<int>& numArr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    std::vector<int> leftBlock(leftSize);
    std::vector<int> rightBlock(rightSize);
    for (int i = 0; i < leftSize; i++) {
        leftBlock[i] = numArr[left + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightBlock[i] = numArr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < leftSize && j < rightSize) {
        if (leftBlock[i] <= rightBlock[j]) {
            numArr[k] = leftBlock[i];
            i++;
        }
        else {
            numArr[k] = rightBlock[j];
            j++;
        }
        k++;
    }
    while (i < leftSize) {
        numArr[k] = leftBlock[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        numArr[k] = rightBlock[j];
        j++;
        k++;
    }
}

// Blocksort implementation
std::vector<int> blockSort(std::vector<int> numArr) {
    int n = numArr.size();
    int blockSize = std::sqrt(n);
    // Sort individual blocks using InsertionSort
    for (int i = 0; i < n; i += blockSize) {
        int left = i;
        int right = std::min(i + blockSize - 1, n - 1);
        insertionSortB(numArr, left, right);
    }
    // Merge sorted blocks using MergeSort technique
    for (int blockSizeMerge = blockSize; blockSizeMerge < n; blockSizeMerge *= 2) {
        for (int i = 0; i < n; i += blockSizeMerge * 2) {
            int left = i;
            int mid = std::min(i + blockSizeMerge - 1, n - 1);
            int right = std::min(i + blockSizeMerge * 2 - 1, n - 1);
            mergeBlocks(numArr, left, mid, right);
        }
    }
    return numArr;
}
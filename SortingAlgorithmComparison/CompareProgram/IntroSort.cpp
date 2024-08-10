#include "IntroSort.h"

// Insertionsort for small subarrays
void insertionSort(std::vector<int>& numArr, int left, int right) {
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

// Heapsort for large subarrays
void heapify(std::vector<int>& numArr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && numArr[left] > numArr[largest]) {
        largest = left;
    }
    if (right < n && numArr[right] > numArr[largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(numArr[i], numArr[largest]);
        heapify(numArr, n, largest);
    }
}

void heapSort(std::vector<int>& numArr, int left, int right) {
    int n = right - left + 1;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(numArr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        std::swap(numArr[0], numArr[i]);
        heapify(numArr, i, 0);
    }
}

// Quicksort with introsort
void quickSort(std::vector<int>& numArr, int left, int right, int depth) {
    if (right - left < 16) {
        insertionSort(numArr, left, right);
        return;
    }
    if (depth > 2 * std::log2(right - left + 1)) {
        heapSort(numArr, left, right);
        return;
    }
    int pivot = numArr[left + (right - left) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (numArr[i] < pivot) {
            i++;
        }
        while (numArr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(numArr[i], numArr[j]);
            i++;
            j--;
        }
    }
    quickSort(numArr, left, j, depth + 1);
    quickSort(numArr, i, right, depth + 1);
}

std::vector<int> introSort(std::vector<int> numArr) {
    quickSort(numArr, 0, numArr.size() - 1, 0);
    return numArr;
}
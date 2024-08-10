#include "CubeSort.h"


#include <vector>
#include <cmath>
#include <algorithm>

// Function to merge two sorted sub-arrays
void mergeC(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];


    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}
// Function to sort each sub-array (local sort)
void localSort(std::vector<int>& arr, int left, int right) {
    std::sort(arr.begin() + left, arr.begin() + right + 1);
}

// Function to perform pairwise exchange and merging
void pairwiseExchangeAndMerge(std::vector<int>& arr, int processor, int dimension, int subArraySize) {
    int partner = processor ^ (1 << dimension);
    int left = std::min(processor, partner) * subArraySize;
    int right = (std::max(processor, partner) + 1) * subArraySize - 1;
    int mid = left + subArraySize - 1;
    if (right < arr.size()) {
        mergeC(arr, left, mid, right);
    }
}

std::vector<int> cubeSort(std::vector<int>& arr) {
    int n = arr.size();
    int numProcessors = 4; // Assuming 4 processors for a 2D hypercube processor = number of sublist
    if (n == 2) numProcessors = 2;
    int subArraySize = n / numProcessors;

    // Step 1: Local sort for each sub-array
    for (int i = 0; i < numProcessors; ++i) {
        localSort(arr, i * subArraySize, (i + 1) * subArraySize - 1);
    }

    // Step 2: Pairwise exchange and merging
    int dimensions = log2(numProcessors);
    for (int k = 0; k < dimensions; ++k) {
        for (int i = 0; i < numProcessors; ++i) {
            pairwiseExchangeAndMerge(arr, i, k, subArraySize);
        }
    }

    return arr;
}
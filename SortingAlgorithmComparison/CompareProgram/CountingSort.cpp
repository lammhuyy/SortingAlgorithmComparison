#include "CountingSort.h"

// CountingSort implementation
std::vector<int> countingSort(std::vector<int>& numArr) {
    int n = numArr.size();
    if (n == 0) {
        return numArr;
    }
    int minVal = *std::min_element(numArr.begin(), numArr.end());
    int maxVal = *std::max_element(numArr.begin(), numArr.end());
    int range = maxVal - minVal + 1;
    std::vector<int> countArr(range, 0);
    // Count occurrences of each value
    for (int i = 0; i < n; i++) {
        countArr[numArr[i] - minVal]++;
    }
    // Calculate cumulative counts
    for (int i = 1; i < range; i++) {
        countArr[i] += countArr[i - 1];
    }
    // Build output array
    std::vector<int> outputArr(n);
    for (int i = 0; i < n; i++) {
        outputArr[countArr[numArr[i] - minVal] - 1] = numArr[i];
        countArr[numArr[i] - minVal]--;
    }
    return outputArr;
}
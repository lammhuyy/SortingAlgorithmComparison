#include <fstream>
#include <vector>
#include <string>

#pragma once

void loadArray(std::string testName, std::vector<int>& numArr, int size);
void saveArray(std::string sortName, int times, std::string testName, std::vector<int>& numArr);
void saveResults(std::vector<std::vector<int>> results, int size, int max);
#include "ioFunctions.h"

void loadArray(std::string testName, std::vector<int>& numArr, int size) {
	std::string path = "../datasets/" + testName;
	std::ifstream input(path);
	if (!input.good())
		return;
	numArr.clear();
	for (int i = 0; i < size; ++i) {
		int temp;
		input >> temp;
		numArr.push_back(temp);
	}
	input.close();
}

void saveArray(std::string sortName, int times, std::string testName, std::vector<int>& numArr) {
	std::string path = "../results/" + sortName + "_" + std::to_string(times) + "_" + testName;
	std::ofstream output(path);
	if (!output.good())
		return;
	int size = numArr.size();
	for (int i = 0; i < size; i++)
		output << numArr[i] << " ";
	output.close();
}

void saveResults(std::vector<std::vector<int>> results, int size, int max) {
	std::string path = "../results_" + std::to_string(size) + "_" + std::to_string(max) + ".txt";
	std::ofstream output(path);
	if (!output.good())
		return;
	for (int distribution = 0; distribution < 3; ++distribution) {
		for (int dataset = 1; dataset <= 2; ++dataset) {
			std::string testName, sortName;
			switch (distribution)
			{
			case 0:
				testName = std::to_string(size) + "random" + std::to_string(max) + "_" + std::to_string(dataset) + ".txt";
				break;
			case 1:
				testName = std::to_string(size) + "forward" + std::to_string(max) + "_" + std::to_string(dataset) + ".txt";
				break;
			case 2:
				testName = std::to_string(size) + "backward" + std::to_string(max) + "_" + std::to_string(dataset) + ".txt";
				break;
			default:
				break;
			}

			output << "========================================" << std::endl;
			output << testName << std::endl;

			for (int sortAlg = 0; sortAlg < 9; ++sortAlg) {
				output << "----------------------------------------" << std::endl;
				switch (sortAlg)
				{
				case 0:
					sortName = "introSort";
					break;
				case 1:
					sortName = "blockSort";
					break;
				case 2:
					sortName = "cubeSort";
					break;
				case 3:
					sortName = "selectionSort";
					break;
				case 4:
					sortName = "insertionSort";
					break;
				case 5:
					sortName = "quickSort";
					break;
				case 6:
					sortName = "mergeSort";
					break;
				case 7:
					sortName = "countingSort";
					break;
				case 8:
					sortName = "radixSort";
					break;
				default:
					break;
				}
				output << sortName << std::endl;

				for (int times = 1; times <= 5; ++times) {
					output << results[sortAlg][distribution * 10 + (dataset - 1) * 5 + times - 1] << "; ";
				}
				output << std::endl;
			}
		}
	}
	output.close();
}
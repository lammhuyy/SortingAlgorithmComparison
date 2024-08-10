#include <fstream>
#include <cstdlib> 
#include <iostream> 
#include <time.h>
#include <string>
using namespace std;

void randGenerator(int num, int max, int times);
void forwardRandGenerator(int num, int max, int times);
void backwardRandGenerator(int num, int max, int times);

int main() {
	int num = 100000, max = 1000000;
	for (int i = 1; i <= 2; ++i) {
		randGenerator(num, max, i);
		forwardRandGenerator(num, max, i);
		backwardRandGenerator(num, max, i);
	}

	return 0;
}

void randGenerator(int num, int max, int times) {
	std::string path = "../datasets/" + std::to_string(num) + "random" + std::to_string(max) + "_" + std::to_string(times) + ".txt";
	ofstream file(path);
	if (!file.good())
		return;

	srand(time(0));
	for (int i = 0; i < num; i++)
		file << rand() % max << " ";
	file.close();
}

void forwardRandGenerator(int num, int max, int times) {
	std::string path = "../datasets/" + std::to_string(num) + "forward" + std::to_string(max) + "_" + std::to_string(times) + ".txt";
	ofstream file(path);
	if (!file.good())
		return;

	srand(time(0));
	int step = max / num;
	for (int i = 0; i < num; i++)
		file << step * i + rand() % step << " ";
	file.close();
}

void backwardRandGenerator(int num, int max, int times) {
	std::string path = "../datasets/" + std::to_string(num) + "backward" + std::to_string(max) + "_" + std::to_string(times) + ".txt";
	ofstream file(path);
	if (!file.good())
		return;

	srand(time(0));
	int step = max / num;
	for (int i = 0; i < num; i++)
		file << step * (num - i) + rand() % step << " ";
	file.close();
}
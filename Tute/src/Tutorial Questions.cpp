#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

int sumTo(const int maxNum);

void printEmployeeName(const employee &emp);

void minmax(const int a, const int b, int &smallerNumOut, int &largerNumOut);

int getIndexOfLargestValue(const int *array, const int arrSize);

const int& getElement(const int *array, const int index);

int main()
{
	

	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}




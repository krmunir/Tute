#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>

void printArray( int(&array)[9]);

int main()
{
	const int length(9);
	int array[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	char sortLocations[length] = {};

	//print unsorted array
	std::cout << "Unsorted array:" << std::endl;
	printArray(array);

	bool isSorted{};
	int arrayIndex{ 0 };

	do {
		arrayIndex = 0;
		isSorted = true; //assume array is sorted, if after a run through all elements any swaps are required set to false
		for (int &val : array) {
			if (array[arrayIndex + 1] < array[arrayIndex]) {
				std::swap(array[arrayIndex + 1], array[arrayIndex]);
				isSorted = false;
				
				//print sort locations
				//clear old locations
				for (char &a : sortLocations) {
					a = ' ';
				}

				//set swap locations
				sortLocations[arrayIndex] = 'X';
				sortLocations[arrayIndex+1] = 'X';

				//print sort locations
				for (char &a : sortLocations)
					std::cout << a << ' ';
				std::cout << std::endl;

				//print array
				printArray(array);
			}
			++arrayIndex;
			if (arrayIndex == 8)
				break; //highest array index is 8
		}

	} while (!isSorted);

	// Now that the whole array is sorted, print our sorted array as proof it works
	std::cout << "Sorted array:" << std::endl;
	printArray(array);

	std::cin.get();

	return 0;
}

void printArray( int(&array)[9]) {
	for (int &element : array)
		std::cout << element << " ";
	std::cout << std::endl << std::endl;
}
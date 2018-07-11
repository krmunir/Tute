#include <iostream>
#include <string>

int main()
{
	int array[] { 4, 6, 7, 3, 8, 2, 1, 9, 5 };
	int searchVal {};

	bool isInvalidEntry = false;
	do
	{
		isInvalidEntry = false;
		std::cout << "Enter an integer between 1 and 9: ";
		std::cin >> searchVal;

		// if the user entered something invalid
		if (std::cin.fail())
		{
			isInvalidEntry = true;
			std::cin.clear(); // reset any error flags
			std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer
		}

		//also invalid if not between 1 and 9
		else if ((searchVal < 1) || (searchVal>9))
			isInvalidEntry = true;

	} while (isInvalidEntry);

	//print whole array
	for (int i = 0; i < 9; ++i)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (const int &val : array)
		std::cout << val << " ";

	//find search value 
	int arrayIndex{ 0 };
	for (const int &val : array) {
		if (val == searchVal) {
			std::cout << std::endl<<searchVal << " found at array index " << arrayIndex;
			break;
		}
		else ++arrayIndex;
	}

	//pause output window
	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}
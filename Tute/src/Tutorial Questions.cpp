#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>


int main()
{
	std::cout << "How many names do you wish to enter?" << std::endl;
	int noOfNames{};
	std::cin >> noOfNames;

	std::string *names = new std::string[noOfNames];

	for (int loop = 0; loop < noOfNames; ++loop)
	{
		std::cout << "Enter name #" << (loop + 1) << ": ";
		std::getline(std::cin, names[loop]);
	}

	//print names
	for (int i = 0; i < noOfNames; ++i)
	{
		std::cout << "Name #" << i << " is " << names[i] << std::endl;
	}


	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}

		
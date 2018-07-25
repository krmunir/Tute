#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include "..\MyString.h"


int main()
{

	MyString string("Hello, world!");
	std::cout << string(7, 5); // start at index 7 and return 5 characters


	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}






#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cstdint>
#include <vector>
#include <initializer_list>
#include <assert.h>


#include "..\IntArray.h"


int main()
{
	IntArray array{ 5, 4, 3, 2, 1 }; // initializer list
	for (int count = 0; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 3, 5, 7, 9, 11 };

	for (int count = 0; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}



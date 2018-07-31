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

#include"..\Fruit.h"


int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColour() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColour() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColour() << ".\n";

	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}



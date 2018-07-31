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
	const Apple a("Red delicious", "red", 4.2);
	std::cout << a;

	const Banana b("Cavendish", "yellow");
	std::cout << b;

	Banana b2("Banana name", "bright yellow");
	std::cout << b2;

	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}



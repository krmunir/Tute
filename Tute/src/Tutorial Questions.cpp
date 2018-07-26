#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cstdint>

#include "..\IntArray.h"

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

//This programs should print:
//5 8 2 3 6
//5 8 2 3 6
int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	//a = a;
	//b = a;

	std::cout << b << '\n';

	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}






#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cstdint>

#include "..\FixedPoint2.h"



int main()
{
	FixedPoint2 a(0.01);
	std::cout << a << '\n';

	FixedPoint2 b(-0.01);
	std::cout << b << '\n';

	FixedPoint2 c(5.01); // stored as 5.0099999... so we'll need to round this
	std::cout << c << '\n';

	FixedPoint2 d(-5.01); // stored as -5.0099999... so we'll need to round this
	std::cout << d << '\n';

	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}






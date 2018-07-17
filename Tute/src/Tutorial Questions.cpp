#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

int factorial(int num);

int main()
{
	std::cout << "3 factorial = " << factorial(3) << std::endl;
	std::cout << "Should be " << (3 * 2) << std::endl << std::endl;

	std::cout << "5 factorial = " << factorial(5) << std::endl;
	std::cout << "Should be " << (5*4*3 * 2) << std::endl << std::endl;

	std::cout << "7 factorial = " << factorial(7) << std::endl;
	std::cout << "Should be " << (7*6*5*4*3 * 2) << std::endl << std::endl;


	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}

int factorial(int num)
{

	if (num > 1)
		return (num*factorial(num - 1));
	
	else 
		return 1;

	
}

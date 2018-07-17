#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>


int sumOfDigits(int num);

int main()
{
	std::cout << "Sum of digits 1234 = " << sumOfDigits(1234) << std::endl;
	std::cout << "should be = " << (1 + 2 + 3 + 4) << std::endl << std::endl;

	std::cout << "Sum of digits 2345 = " << sumOfDigits(2345) << std::endl;
	std::cout << "should be = " << (2 + 3 + 4+5) << std::endl << std::endl;

	std::cout << "Sum of digits 3456 = " << sumOfDigits(3456) << std::endl;
	std::cout << "should be = " << (3 + 4+5+6) << std::endl << std::endl;

	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}

int sumOfDigits(int num)
{
	if (num  <10) {
		return num;
	}
	else {	
		return (num%10+sumOfDigits(num / 10));
	}
}

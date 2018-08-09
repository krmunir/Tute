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
#include <vector>
#include <stdexcept>

//Write a Fraction class that has a constructor that takes a numerator and a denominator. If the user passes in a denominator of 0, throw an exception of type std::runtime_error (included in the stdexcept header). In your main program, ask the user to enter two integers. If the Fraction is valid, print the fraction. If the Fraction is invalid, catch a std::exception, and tell the user that they entered an invalid fraction.

class Fraction {
public:
	Fraction(int num, int den) try : m_num{ num }, m_den{ den } {
		if (0 == m_den) throw std::runtime_error("Invalid denominator entered");
	}
	catch (std::exception &exception) {
		throw;
	}
	//private:
	int m_num{ 0 };
	int m_den{ 1 };
};

int main()
{
	int num{ 0 }, den{ 1 };
	std::cout << "Enter numerator: ";
	std::cin >> num;
	std::cout << "Enter denominator: ";
	std::cin >> den;

	try
	{
		Fraction f(num, den);
		std::cout << "Fraction is " << f.m_num << "/" << f.m_den << std::endl;

	}
	catch (const std::exception& exception)
	{
		std::cerr << "Exception thrown: " << exception.what();
	}

	return 0;
}













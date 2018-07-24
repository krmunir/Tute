#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include "..\Fraction.h"

Fraction operator*(Fraction f, int i);
Fraction operator*(Fraction f1, Fraction f2);


int main()
{
	
	Fraction f1(2, 5);
	f1.print();

	Fraction f2(3, 8);
	f2.print();

	Fraction f3 = f1 * f2;
	f3.print();

	Fraction f4 = f1 * 2;
	f4.print();

	Fraction f5 = 2 * f2;
	f5.print();

	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.print();


	//std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}


Fraction operator*(Fraction f, int i) {
	Fraction result;
	result.m_num = f.m_num*i;
	result.m_den = f.m_den;
	int GCD = result.gcd(result.m_num, result.m_den);
	result.m_num /= GCD;
	result.m_den /= GCD;

	return result;
}

Fraction operator*(Fraction f1, Fraction f2) {
	Fraction result;
	result.m_num = f1.m_num*f2.m_num;
	result.m_den = f1.m_den*f2.m_den;
	int GCD = result.gcd(result.m_num, result.m_den);
	result.m_num /= GCD;
	result.m_den /= GCD;

	return result;

}

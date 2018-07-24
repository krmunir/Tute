#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include "..\Fraction.h"

//Fraction operator*(Fraction f, int i);
//Fraction operator*(Fraction f1, Fraction f2);


int main()
{
	
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';


	std::cin.ignore(32767, '\n');
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

std::ostream& operator<<(std::ostream& out, Fraction &f) {
	out << f.m_num << " / " << f.m_den << " ";
	return out;
}

std::istream& operator>>(std::istream& in, Fraction &f) {
	in >> f.m_num >> f.m_den;
	return in;
}
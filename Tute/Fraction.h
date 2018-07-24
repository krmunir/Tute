#pragma once

#include <iostream>
//Add overloaded multiplication operators to handle multiplication between a Fraction and integer, and between two Fractions. 
//Use the friend function method.

class Fraction
{
private:
	int m_num;
	int m_den;
public:
	Fraction(int num=0, int den=1) : m_num{num}, m_den{den} {}

	void print() {
		std::cout << "Fraction = " << m_num << " / " << m_den << std::endl;
	}
	friend Fraction operator*(Fraction f, int i);
	friend Fraction operator*(Fraction f1, Fraction f2);
	friend std::ostream& operator<<(std::ostream& out, Fraction &f);
	friend std::istream& operator>>(std::istream& in, Fraction &f);
private:
	int gcd(int a, int b) {
		return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
	}
};


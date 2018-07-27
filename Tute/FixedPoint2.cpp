#include <iostream>
#include <math.h>

#include "FixedPoint2.h"

std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp) {
	double result{};
	result = static_cast<double>(fp.m_wholeNum) + (static_cast<double>(fp.m_fraction) / 100);
	out << result << std::endl;
	return out;
}
//now add a constructor that takes a double. You can round a number (on the left of the decimal) by using the round() function (included in header cmath).
//
//Hint: You can get the non - fractional part of a double by static casting the double to an integer
//	Hint : To get the fractional part of a double, you’ll first need to zero - out the non - fractional part.Use the integer value to do this.
//	Hint : You can move a digit from the right of the decimal to the left of the decimal by multiplying by 10. You can move it two digits by multiplying by 100. as negative. Provide the overloaded operators and constructors required for the following program to run:

FixedPoint2::FixedPoint2(double num) {
	double b = round(100 * num);
	double temp = b / 100;
	m_wholeNum = static_cast<int>(temp);
	m_fraction = static_cast<int>(b)%100;
}

bool operator==(FixedPoint2& fp1, FixedPoint2& fp2) {
	if ((fp1.m_wholeNum == fp2.m_wholeNum) && (fp1.m_fraction == fp2.m_fraction))
		return true;
	else
		return false;
}

std::istream& operator>>(std::istream& in, FixedPoint2& fp) {
	double num;
	in >> num;
	double b = round(100 * num);
	double temp = b / 100;
	fp.m_wholeNum = static_cast<int>(temp);
	fp.m_fraction = static_cast<int>(b) % 100;
	return in;
}

FixedPoint2& operator+(FixedPoint2& fp1, FixedPoint2& fp2) {
	double num1{static_cast<double>(fp1)};
	double num2{static_cast<double>(fp2)};
	FixedPoint2 result{ num1 + num2 };
	return result;
}




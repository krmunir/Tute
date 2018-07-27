#pragma once

#include <cstdint>

//now add a constructor that takes a double. You can round a number (on the left of the decimal) by using the round() function (included in header cmath).
//
//Hint: You can get the non - fractional part of a double by static casting the double to an integer
//	Hint : To get the fractional part of a double, you’ll first need to zero - out the non - fractional part.Use the integer value to do this.
//	Hint : You can move a digit from the right of the decimal to the left of the decimal by multiplying by 10. You can move it two digits by multiplying by 100. as negative. Provide the overloaded operators and constructors required for the following program to run:
class FixedPoint2
{
private:
	int16_t m_wholeNum;
	int8_t m_fraction;

public:
	FixedPoint2(int16_t whole = 0, int8_t frac = 0) : m_wholeNum{ whole }, m_fraction{ frac } {
		if (m_wholeNum < 0)
			if (!(m_fraction < 0))
				m_fraction = -m_fraction;
		if (m_fraction < 0)
			if (!(m_wholeNum < 0))
				m_wholeNum = -m_wholeNum;
	}
	FixedPoint2(double num);
	friend std::ostream& operator<<(std::ostream& out, FixedPoint2& fp);
	operator double() {
		double resultnotinit;
		double result{};
		result = static_cast<double>(m_wholeNum) + (static_cast<double>(m_fraction) / 100);
		return result;
	}
};


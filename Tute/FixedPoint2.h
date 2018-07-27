#pragma once

#include <cstdint>

//Write a class named FixedPoint2 that implements the recommended solution from the previous question. If either (or both) of the non-fractional and fractional part of the number are negative, the number should be treated as negative. Provide the overloaded operators and constructors required for the following program to run:
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
	friend std::ostream& operator<<(std::ostream& out, FixedPoint2& fp);
	operator double() {
		double resultnotinit;
		double result{};
		result = static_cast<double>(m_wholeNum) + (static_cast<double>(m_fraction) / 100);
		return result;
	}
};


#pragma once

#include <cstdint>

//Overload operator==, operator >>, operator- (unary), and operator+ (binary)
//Hint: Add your two FixedPoint2 together by leveraging the double cast, adding the results, and converting back to a FixedPoint2.
//Hint: For operator>>, use your double constructor to create an anonymous object of type FixedPoint2, and assign it to your FixedPoint2 function parameter


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
	friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp);
	operator double() {
		double resultnotinit;
		double result{};
		result = static_cast<double>(m_wholeNum) + (static_cast<double>(m_fraction) / 100);
		return result;
	}
	friend bool operator==(FixedPoint2& fp1, FixedPoint2& fp2);
	friend std::istream& operator>>(std::istream& in, FixedPoint2& fp);
	FixedPoint2& operator-() {
		int16_t whole{-m_wholeNum};
		int8_t frac{-m_fraction};
		FixedPoint2 result{ whole, frac };
		return result;




	}
	friend FixedPoint2& operator+(FixedPoint2& fp1, FixedPoint2& fp2);
};


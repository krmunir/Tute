#include <iostream>

#include "FixedPoint2.h"

std::ostream& operator<<(std::ostream& out, FixedPoint2& fp) {
	double result{};
	result = static_cast<double>(fp.m_wholeNum) + (static_cast<double>(fp.m_fraction) / 100);
	out << result << std::endl;
	return out;
}


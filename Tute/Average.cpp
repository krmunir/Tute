#include "Average.h"

Average& Average::operator+=(int num) {
	m_sum += num;
	++m_no;
	return *this;
}

std::ostream& operator<<(std::ostream& out, Average& ave) {
	std::cout << (static_cast<float>(ave.m_sum) / static_cast<float>(ave.m_no));
	return out;
}

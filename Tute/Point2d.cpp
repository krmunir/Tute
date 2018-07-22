
#include <iostream>
#include <cmath>


#include "Point2d.h"



void Point2d::print() {
	std::cout << "Point2d(" << m_x << ", " << m_y << ")" << std::endl;
}

float Point2d::distanceTo(Point2d &p2) {
	return (sqrt((p2.m_x - m_x)*(p2.m_x - m_x) + (p2.m_y - m_y)*(p2.m_y - m_y)));
}

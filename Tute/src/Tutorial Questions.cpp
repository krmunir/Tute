#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include "Point2d.h"


float distanceFrom(Point2d &p1, Point2d &p2);


int main()
{
	
	Point2d first;
	Point2d second(3.0, 4.0);
	first.print();
	second.print();
	std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

	
	//std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}

float distanceFrom(Point2d &p1,Point2d &p2) {
	return (sqrt((p2.m_x - p1.m_x)*(p2.m_x - p1.m_x) + (p2.m_y - p1.m_y)*(p2.m_y - p1.m_y)));
}

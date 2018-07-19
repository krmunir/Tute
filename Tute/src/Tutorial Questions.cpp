#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>


int main()
{
	class Point3d {
	public:
		float m_x{ 0 };
		float m_y{ 0 };
		float m_z{ 0 };

		void setValues(float a, float b, float c) {
			m_x = a;
			m_y = b;
			m_z = c;
		}
		
		void print() {
			std::cout << "<" << m_x<< ", " << m_y << ", " << m_z << ">" << std::endl;
		}

		bool isEqual(Point3d p) {
			if ((p.m_x == m_x) && (p.m_y == m_y) && (p.m_z == m_z))
				return true;
			else
				return false;
		}
	};

	

	Point3d point1;
	point1.setValues(1.0, 2.0, 3.0);

	Point3d point2;
	point2.setValues(1.0, 2.0, 3.0);

	if (point1.isEqual(point2))
		std::cout << "point1 and point2 are equal\n";
	else
		std::cout << "point1 and point2 are not equal\n";

	Point3d point3;
	point3.setValues(3.0, 4.0, 5.0);

	if (point1.isEqual(point3))
		std::cout << "point1 and point3 are equal\n";
	else
		std::cout << "point1 and point3 are not equal\n";

	//std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}



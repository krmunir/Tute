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

	};

	

	Point3d point;
	point.setValues(1.0, 2.0, 3.0);

	point.print();

	//std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}



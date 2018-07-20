#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cassert>

enum class Colour {
	black,
	white,
	blue,
	red
};

int main()
{
	class Ball {
	private:
		Colour m_colour{ Colour::black };
		float m_radius{ 10.0 };
	public:
		Ball() {};
		Ball(Colour col) {
			m_colour = col;
		}
		Ball(float rad) {
			m_radius = rad;
		}
		Ball(Colour col, float rad) {
			m_colour = col;
			m_radius = rad;
		}
		void print() {
			std::cout << "colour: " << static_cast<int> (m_colour) << ", radius: " << m_radius << std::endl;
		}
		
	};

	Ball def;
	def.print();

	Ball blue(Colour::blue);
	blue.print();

	Ball twenty(20.0);
	twenty.print();

	Ball blueTwenty(Colour::blue, 20.0);
	blueTwenty.print();

	//std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}



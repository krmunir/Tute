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
		Colour m_colour;
		float m_radius;
	public:
		Ball(Colour col = Colour::black, float rad = 10.0) {
			m_colour = col;
			m_radius = rad;
		}
		Ball(float rad = 10.0) {
				m_radius = rad;
				m_colour = Colour::black;
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



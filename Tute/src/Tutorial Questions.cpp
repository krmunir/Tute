#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cassert>


int main()
{
	class RGBA {
	private:
		std::uint8_t m_red; 
		std::uint8_t m_green;
		std::uint8_t m_blue;
		std::uint8_t m_alpha;

	public:
		RGBA(std::uint8_t r=0, std::uint8_t g=0, std::uint8_t b=0, std::uint8_t a=255)
			: m_red{ r },
			m_green{ g },
			m_blue{ b },
			m_alpha{ a }
		{}

		void print() {
			std::cout << "r=" << static_cast<int> (m_red) << ", g=" << static_cast<int> (m_green) << ", b=" << static_cast<int> (m_blue) << ", a=" << static_cast<int> (m_alpha);
		}
	};

	RGBA teal(0, 127, 127);
	teal.print();


	//std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}



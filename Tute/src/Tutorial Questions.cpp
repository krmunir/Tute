#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>


int main()
{
	class IntPair {
	public:
		int a{ 0 };
		int b{ 0 };

		void set(int x, int y) {
			a = x;
			b = y;
		}

		void print() {
			std::cout << a << " " << b << std::endl;
		}
	};

	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2{ 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();



	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}



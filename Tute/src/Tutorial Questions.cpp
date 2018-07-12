#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>

void swap(int &x, int &y);

int main()
{
	int a{ 4 }, b{ 9 };

	std::cout << "before swap" << a << " " << b << std::endl;
	swap(a, b);
	std::cout << "after swap" << a << " " << b << std::endl;

	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}

void swap(int &x, int &y) {
	int temp{};
	temp = x;
	x = y;
	y = temp;
}

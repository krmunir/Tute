#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>


int main()
{
	const char *cStyleString = "Hello world!";
	int i{ 0 };

	do
	{
		std::cout << cStyleString[i];
		++i;
	} while (cStyleString[i] !='\0');

	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}


#include <iostream>
#include<string>


int main() {

	for (int i = 0; i <= 20; ++i)
	{
		if (i % 2 == 0)
			std::cout << i << '\n';
	}

	std::cin.get();

	return 0;
}


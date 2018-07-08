#include <iostream>
#include<string>


int main() {

	char character='A';

	while (character <= 'Z') {
		std::cout << character << " " << static_cast<int> (character) << std::endl;
		++character;
	}
	
	std::cin.get();

	return 0;
}


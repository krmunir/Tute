#include <iostream>
#include<string>

struct fraction {
	float numerator = 0;
	float denominator = 0;
};

int main() {
	fraction frac1{ };
	fraction frac2{ };

	std::cout << "Enter numerator fraction 1: ";
	std::cin >> frac1.numerator;

	std::cout << std::endl << "Enter denominator fraction 1: ";
	std::cin >> frac1.denominator;

	std::cout << std::endl << "Enter numerator fraction 2: ";
	std::cin >> frac2.numerator;

	std::cout << std::endl << "Enter denominator fraction 2: ";
	std::cin >> frac2.denominator;

	std::cout << std::endl << "Product = " << ((frac1.numerator*frac2.numerator) / (frac1.denominator*frac2.denominator)) << std::endl;
	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}
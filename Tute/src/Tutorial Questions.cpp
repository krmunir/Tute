#include <iostream>
#include<string>

int sumTo(int val);

int main() {
	int num{};

	std::cout << "Enter a number: ";
	std::cin >> num;
	std::cout << '\n' << "The sum is " << sumTo(num) << '\n';

	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}

int sumTo(int val) {
	int sum{ 0 };

	for (int i = 1; i <=val; ++i)
	{
		sum += i;
	}

	return sum;
}

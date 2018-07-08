#include <iostream>
#include<string>

enum class errorCode {
	SUCCESS=0,
	INVALID_OPERATOR=-1
};

struct calcResult {
	int value;
	errorCode errcode;
};

calcResult	calculate(int val1, char op, int val2);

int main() {
	int a, b;
	char op;
	calcResult result{};

	std::cout << "Enter expression a <operator> b: ";
	std::cin >> a >> op >> b;

	result = calculate(a, op, b);

	if (result.errcode == errorCode::INVALID_OPERATOR)
		std::cout << std::endl << "An invalid operator was entered." << std::endl;
	else
		std::cout << std::endl << result.value;
	std::cin.ignore(32767, '\n');
	std::cin.get();
	
	return 0;
}

calcResult	calculate(int val1, char op, int val2) {
	calcResult result{};

	switch (op)
	{
	case '+':
		result.value= (val1 + val2);
		result.errcode = errorCode::SUCCESS;
		return result;
	case '-':
		result.value = (val1 - val2);
		result.errcode = errorCode::SUCCESS;
		return result;
	case '*':
		result.value = (val1 * val2);
		result.errcode = errorCode::SUCCESS;
		return result;
	case '/':
		result.value = (val1 / val2);
		result.errcode = errorCode::SUCCESS;
		return result;
	case '%':
		result.value = (val1 % val2);
		result.errcode = errorCode::SUCCESS;
		return result;
	default:
		result.errcode = errorCode::INVALID_OPERATOR;
		return result;
	}
}
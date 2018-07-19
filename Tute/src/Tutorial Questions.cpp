#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cassert>

int main()
{

	class Stack {
	public:
		void reset() {
			length = 0;
			for (int val : array)
				val = 0;
		}

		bool push(int a) {
			if (length == 10)
				return false; //stack full
			else {
				array[length] = a;
				++length; //increment length to point to next vacant position in stack
			}
		}

		int pop() {
			assert(length != 0);
			--length;
			return array[length];
		}

		void print() {
						
			std::cout << "( ";

			for (int i = 0; i < length; ++i)
				std::cout << array[i] << " ";

			std::cout << ")"<<std::endl;

		}

	private:
		int array[10]{ 0 };
		int length{ 0 };
	};

	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	//std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}



#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cassert>



class HelloWorld
{
private:
	char *m_data;

public:
	HelloWorld()
	{
		m_data = new char[14];
		const char *init = "Hello, World!";
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
	}

	~HelloWorld()
	{
		// replace this comment with your destructor implementation
		delete[] m_data;
	}

	void print() const
	{
		std::cout << m_data;
	}

};

int main()
{
	

	HelloWorld hello;
	hello.print();

	
	//std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}




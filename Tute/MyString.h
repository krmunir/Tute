#pragma once
#include <string>

////Write a class that holds a string. Overload operator() to return the substring that starts at the index of the first parameter. The length of the substring should be defined by the second parameter.
//
//Hint: You can use array indices to access individual chars within the std::string
//	Hint : You can use operator+= to append something to a string
class MyString
{
private:	
	std::string m_string;
public:
	MyString(std::string string);
	std::string operator()(int start, int len);
};


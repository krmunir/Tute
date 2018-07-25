#include "MyString.h"



MyString::MyString(std::string string)
{
	m_string = string;
}


//Write a class that holds a string.Overload operator() to return the substring that starts at the index of the first parameter.
//The length of the substring should be defined by the second parameter.
//Hint : You can use array indices to access individual chars within the std::string
//Hint : You can use operator+= to append something to a string
std::string MyString::operator()(int start, int len){
	std::string substring{};
	//int subindex{ 0 };
	for (int index = start; index < (start+len); ++index)
	{
		substring += m_string[index];
		//++subindex;
	}
	//substring[subindex] = '\0';
	return substring;
}

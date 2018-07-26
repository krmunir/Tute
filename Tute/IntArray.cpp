#include <assert.h>
#include <iostream>
#include <iterator>

#include "IntArray.h"


IntArray::IntArray(int size)
{
	assert(size >= 0 && "Array size must be greater than or equal to zero");
	
	m_array = new (std::nothrow) int(size);
	assert(m_array != nullptr&&"Error allocating memory to array");

	m_arraySize = size;
	std::cout << "Array dynamically created of size : " << m_arraySize << std::endl;
}


IntArray::~IntArray()
{
	delete m_array;
	std::cout << "Dynamically created array has been deleted!" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const IntArray arr) {
	for (int i = 0; i < arr.m_arraySize; ++i)
	{
		std::cout << arr.m_array[i] << " ";
	}
	return out;
}

int& IntArray::operator[](int elementNum) {
	return m_array[elementNum];
}
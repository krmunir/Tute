#pragma once

//Write your own integer array class named IntArray from scratch (do not use std::array or std::vector). Users should pass in the size of the array when it is created, and the array should be dynamically allocated. Use assert statements to guard against bad data. Create any constructors or overloaded operators needed to make the following program operate correctly:

class IntArray
{
private:
	int *m_array = nullptr;
	int m_arraySize = 0;
public:
	IntArray(int size);
	~IntArray();
	// Copy constructor that does a deep copy
	IntArray(const IntArray &array) :
		m_arraySize(array.m_arraySize)
	{
		// Allocate a new array
		m_array = new int[m_arraySize];

		// Copy elements from original array to new array
		for (int count = 0; count < array.m_arraySize; ++count)
			m_array[count] = array.m_array[count];
	}
	friend std::ostream& operator<<(std::ostream& out, const IntArray arr);
	int& operator[](int elementNum);
};


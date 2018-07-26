#pragma once

//Write your own integer array class named IntArray from scratch (do not use std::array or std::vector). Users should pass in the size of the array when it is created, and the array should be dynamically allocated. Use assert statements to guard against bad data. Create any constructors or overloaded operators needed to make the following program operate correctly:

class IntArray
{
private:
	int *m_array;
	int m_arraySize;
public:
	IntArray(int size);
	~IntArray();
	friend std::ostream& operator<<(std::ostream& out, const IntArray arr);
	int& operator[](int elementNum);
};


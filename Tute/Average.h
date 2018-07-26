#pragma once
#include <cstdint>
#include <iostream>

//Write a class named Average that will keep track of the average of all integers passed to it. Use two members: The first one should be type int32_t, and used to keep track of the sum of all the numbers you’ve seen so far. The second should be of type int8_t, and used to keep track of how many numbers you’ve seen so far. You can divide them to find your average.

class Average
{
private:
	int32_t m_sum;
	int8_t m_no;
public:
	Average() :m_sum{ 0 }, m_no{ 0 } {}
	Average& operator+=(int num);
	friend std::ostream& operator<<(std::ostream& out, Average& ave);
};


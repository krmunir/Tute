#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cstdint>
#include <vector>
#include <initializer_list>
#include <assert.h>



//Create an abstract class named Shape. This class should have three functions: a pure virtual print function that takes and returns a std::ostream, an overloaded operator<< and an empty virtual destructor.
class Shape {
private:
protected:
public:
	virtual std::ostream& print(std::ostream& out) const = 0;
	friend std::ostream& operator<<(std::ostream& out, Shape &shape) const { return shape.print(out); }
	virtual ~Shape() {}
};

class Point
{
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;

public:
	Point(int x, int y, int z)
		: m_x(x), m_y(y), m_z(z)
	{

	}

	friend std::ostream& operator<<(std::ostream &out, const Point &p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};

class Circle : public Shape {
private:
	Point m_centre{};
	int radius{};
public:
	Circle(Point p,int r):m_centre{p}
	virtual  std::ostream& print(std::ostream& out) const override {

	}


};

class Triangle : public Shape {
private:
	Point m_p1{ 0,0,0 };
	Point m_p2{ 0,0,0 };
	Point m_p3{ 0,0,0 };

public:
	virtual  std::ostream& print(std::ostream& out) const override {

	}

};


int main()
{

	Circle c(Point(1, 2, 3), 7);
	std::cout << c << '\n';

	Triangle t(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9));
	std::cout << t << '\n';

	return 0;
}









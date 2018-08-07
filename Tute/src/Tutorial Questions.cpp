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
#include <vector>


//Create an abstract class named Shape. This class should have three functions: a pure virtual print function that takes and returns a std::ostream, an overloaded operator<< and an empty virtual destructor.
class Shape {
private:
protected:
public:
	virtual std::ostream& print(std::ostream& out) const = 0;
	friend std::ostream& operator<<(std::ostream& out, Shape &shape) { return shape.print(out); }
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
		: m_x(x), m_y(y), m_z(z) {}
	
	friend std::ostream& operator<<(std::ostream &out, const Point &p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};

class Circle : public Shape {
private:
	Point m_centre;
	int m_radius{};
public:
	Circle(Point p, int r) : m_centre{ p }, m_radius{ r } {}
	virtual  std::ostream& print(std::ostream& out) const override {
		out << "Circle(" << m_centre << ", radius " << m_radius << ")" << std::endl;
		return out;
	}
	int getRadius() { return m_radius; }

};

class Triangle : public Shape {
private:
	Point m_p1{ 0,0,0 };
	Point m_p2{ 0,0,0 };
	Point m_p3{ 0,0,0 };

public:
	Triangle(Point p1, Point p2, Point p3) : m_p1{ p1 }, m_p2{ p2 }, m_p3{ p3 } {}
	virtual  std::ostream& print(std::ostream& out) const override {
		out << "Triangle(" << m_p1<<", " << m_p2 <<", " << m_p3 << ")" << std::endl;
		return out;
	}

};

int getLargestRadius(std::vector<Shape*> shape);

int main()
{

	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));

	// print each shape in vector v on its own line here

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

																		   // delete each element in the vector here


	return 0;
}

int getLargestRadius(std::vector<Shape*> shape) {
	int largestRad{ 0 };
	Circle* circPtr;

	for (auto *shpntr : shape)
	{
		circPtr = dynamic_cast<Circle*>(shpntr);
		if (circPtr) {
			if (circPtr->getRadius() > largestRad) {
				largestRad = circPtr->getRadius();
			}
		}
	}
	return largestRad;
}








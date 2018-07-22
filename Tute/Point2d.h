#pragma once


class Point2d
{
private:
	double m_x;
	double m_y;
public:
	Point2d(double x=0.0, double y=0.0) : m_x{ x }, m_y{ y } {}
	void print();
	friend float distanceFrom(Point2d &p1, Point2d &p2);

};


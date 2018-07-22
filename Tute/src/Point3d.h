#pragma once

//#include "Vector3d.h"  //this doesnt work as you end up with circular includes: Vector3d.h includes Point3d.h and vice versa
class Vector3d;

class Point3d
{
private:
	double m_x, m_y, m_z;

public:
	Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x(x), m_y(y), m_z(z)
	{
	}
	void print(); 
	void moveByVector(const Vector3d &v);
};

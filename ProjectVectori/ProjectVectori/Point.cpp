#include "Point.h"

Point::Point():x(0),y(0),z(0)
{
}

Point::Point(double x, double y, double z):x(x),y(y),z(z)
{
}

Point::Point(const Point & p)
{
	x = p.x;
	y = p.y;
	z = p.z;
}


Point::~Point()
{
}

Point & Point::operator=(const Point & rhs)
{
	if (this != &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
	}
	return *this;
}

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

double Point::getZ() const
{
	return z;
}

bool Point::operator==(const Point & rhs)
{
	if (x==rhs.x && y==rhs.y && z==rhs.z) return true;

	else return false;
}

std::ostream & operator<<(std::ostream & out, const Point & rhs)
{
	return out<<"(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
}

std::istream & operator>>(std::istream & in, Point & rhs)
{
	double x, y, z;
	std::cout << "Моля въведете стойност x на точката: ";
	in >> x;
	std::cout << "Моля въведете стойност y на точката: " ;
	in >> y;
	std::cout << "Моля въведете стойност z на точката: " ;
	in >> z;
	
	rhs.x = x; rhs.y = y; rhs.z = z;
	return in;
}

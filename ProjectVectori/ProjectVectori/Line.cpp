#include "Line.h"



Line::Line()
{
}

Line::Line(const Line & rhs)
{
	startPoint = rhs.startPoint;
	lineDirection = rhs.lineDirection;
}

Line::Line(const Point & a, const Vector & b)
{
	startPoint.x = a.x + b.x;
	startPoint.y = a.y + b.y;
	startPoint.z = a.z + b.z;
	lineDirection = b;

}

Line::Line(const Point & a, const Point & b)
{
	Vector v(a, b);
	Line(a, v);
}


Line::~Line()
{
}

Line & Line::operator=(const Line & rhs)
{
	if (this != &rhs)
	{
		startPoint = rhs.startPoint;
		lineDirection = rhs.lineDirection;
	}
	return *this;
}

Vector Line::getDirection()
{
	return lineDirection;
}

Vector Line::getNormalVector()
{
	Vector normal;
	Vector v2(startPoint.x, startPoint.y, startPoint.z);
	normal = lineDirection ^ v2;
	return normal;
}

double Line::getAngle(Line & l)
{
	
	double angle = ((this->lineDirection.x*l.lineDirection.x) + (this->lineDirection.y*l.lineDirection.y) + (this->lineDirection.z*l.lineDirection.z))
		/ (this->lineDirection.length() * l.lineDirection.length());
	std::cout << angle<<std::endl;
	return acos(angle);
}

void Line::setLinePV( Point & a,  Vector & b)
{
	std::cin >> a >> b;
	startPoint.x = a.x + b.x;
	startPoint.y = a.y + b.y;
	startPoint.z = a.z + b.z;
	lineDirection = b;
}

void Line::setLinePP( Point & a,  Point & b)
{
	std::cin >> a >> b;
	Vector v(a, b);
	startPoint.x = a.x + v.x;
	startPoint.y = a.y + v.y;
	startPoint.z = a.z + v.z;
	lineDirection = v;
	std::cout << lineDirection.length();
}

bool operator+(Point & r, Line & p)
{
	//if ((p.lineDirection.y - r.y)*vz - (pz - rz)*vy == 0
	//	(pz - rz)*vx - (px - rx)*vz == 0
	//	(px - rx)*vy - (py - ry)*vx == 0){}

	return false;
}

std::istream & operator>>(std::istream & in, Line & l)
{
	int num;
	Point a, b;
	Vector v;
	std::cout << "Моля изберете как ще се създаде обекта:\n";
	std::cout << "1 - Чрез точка и вектор.\n"<< "2 - Чрез 2 точки.\n" ;
	in >> num;
	switch (num) {
	case 1:
		in >> a >> v;
		l.startPoint.x = a.x + v.x;
		l.startPoint.y = a.y + v.y;
		l.startPoint.z = a.z + v.z;
		l.lineDirection = v;
		break;
	case 2:
		in >> a >> b;
	//	v(a, b);
		l.startPoint.x = a.x + v.x;
		l.startPoint.y = a.y + v.y;
		l.startPoint.z = a.z + v.z;
		l.lineDirection = v;
		break;
	default:
		break;
	}
	
	return in;
}

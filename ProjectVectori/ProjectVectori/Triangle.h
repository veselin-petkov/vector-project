#pragma once
#include "Point.h"
#include "EqualPointException.h"
#include "Vector.h"

class Triangle :
	public Point, public EqualPointException, public Vector
{
public:
	Point A;
	Point B;
	Point C;


	Triangle();
	Triangle(Point&, Point&, Point&);
	~Triangle();
	Triangle(const Triangle &);
	Triangle& operator=(const Triangle&);

	void triangleType();
	double perimeter(const Triangle &) const;
	double perimeter() const;
	double area(const Triangle &) const;
	double area() const;
	Point medicenter() const;
};

std::ostream& operator<< (std::ostream &, const Triangle &);
std::istream& operator>> (std::istream &, Triangle &);
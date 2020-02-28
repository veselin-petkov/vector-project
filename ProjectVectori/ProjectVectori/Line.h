#pragma once
#include "Vector.h"
class Line :
	public Vector
{
public:
	Line();
	Line(const Line &);
	Line(const Point &, const Vector &);
	Line(const Point &, const Point &);
	~Line();
	Line& operator=(const Line &);

	Vector getDirection();
	Vector getNormalVector();
	double getAngle( Line &);
	friend bool operator+(Point&, Line &);
	void setLinePV( Point &,  Vector &);
	void setLinePP( Point &,  Point &);
public:
	Point startPoint;
	Vector lineDirection;
};

bool operator+(Point&,Line &);

std::istream& operator>> (std::istream &, Line &);

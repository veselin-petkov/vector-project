#pragma once
#include "Element.h"
class Point :
	public Element
{
public:
	double x, y, z;
public:
	Point();
	Point(double, double, double);
	Point(const Point &);
	~Point();
	Point & operator=(const Point &);

	double getX() const; 
	double getY() const;
	double getZ() const;
	bool operator==(const Point&);
	//friend bool operator+(Point&, Line &);
	//virtual std::ostream& ins(std::ostream &)const;
};

std::ostream& operator<< (std::ostream &, const Point &);
std::istream& operator>> (std::istream &, Point &);
//std::ostream& operator<< (std::ostream &, const Building &);
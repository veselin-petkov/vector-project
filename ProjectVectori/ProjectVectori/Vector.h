#pragma once
#include "Point.h"
#include "VectorLengthException.h"

class Vector :
	public Point, public VectorLengthException
{
public:
	Vector();
	Vector(double, double, double);
	Vector(const Point&,const Point &);
	Vector(const Vector &);
	~Vector();
	Vector& operator=(const Vector &);

	double length(const Vector&);
	double length() const;
	Vector direction() const;
	bool zeroVector(const Vector &);
	bool zeroVector();
	Vector projection(const Vector &) const;
	bool parallelism(const Vector &);
	bool perpendicular(const Vector &);
	Vector operator+(const Vector&);
	Vector operator-(const Vector&);
	double operator*(const Vector&);
	Vector operator*(double );
	Vector operator^(const Vector&);
	double operator()(const Vector&, const Vector&);
};
std::ostream& operator<< (std::ostream &, const Vector &);
std::istream& operator>> (std::istream &, Vector &);

#include "Vector.h"

Vector::Vector()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector::Vector(double x, double y, double z):Point(x,y,z){
}

Vector::Vector(const Point & A, const Point & B): Vector(B.x - A.x, B.y - A.y, B.z - A.z)
{
}

Vector::Vector(const Vector & rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
}

Vector::~Vector()
{
}

Vector & Vector::operator=(const Vector & rhs)
{
	if (this != &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
	}
	return *this;
}

double Vector::length(const Vector & b)
{
	return sqrt(pow(b.x, 2) + pow(b.y, 2) + pow(b.z, 2));
}

double Vector::length() const
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector Vector::direction() const
{
	try {
		if (length() == 0) {
			throw VectorLengthException();
		}
		else return Vector(x / length(), y / length(), z / length());
	}
	catch (VectorLengthException& e) {
		std::cout << e.what() << std::endl;
	}
}

bool Vector::zeroVector(const Vector & rhs)
{
	if (rhs.x == 0 && rhs.y == 0 & rhs.z == 0) return true;
	else return false;
}

bool Vector::zeroVector()
{
	if (x == 0 && y == 0 && z == 0) return true;
	else return false;
}

Vector Vector::projection(const Vector& rhs) const
{
	double upSide = (x * rhs.x) + (y * rhs.y) + (z * rhs.z);
	double downSide = pow(rhs.length(), 2);
	double all = upSide / downSide;
	return Vector(all * rhs.x, all * rhs.y, all * rhs.z);
}

bool Vector::parallelism(const Vector & rhs)
{
	try {
		if (length() == 0 || length(rhs) == 0) {
			throw VectorLengthException();
		} //throws VectorLengthException if length is equal to zero
		else if (x / rhs.x == y / rhs.y  &&  x / rhs.x == z / rhs.z && y / rhs.y == rhs.z) return true;
		else return false;
	}
	catch (VectorLengthException& e) {
		std::cout << e.what() << std::endl;
	}	
}

bool Vector::perpendicular(const Vector & rhs)
{
	try {
		if (length() == 0 || length(rhs) == 0) {
			throw VectorLengthException();
		}

		else if ((x*rhs.x) + (y*rhs.y) + (z*rhs.z) == 0) return true;
		else return false;
	}
	catch (VectorLengthException& e) {
		std::cout << e.what() << std::endl;
	}
}

Vector  Vector::operator+(const Vector & rhs)
{
	
	return Vector(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector Vector::operator-(const Vector & rhs)
{
	return Vector(x - rhs.x, y - rhs.y, z - rhs.z);
}

double Vector::operator*(const Vector & rhs)
{
	double sum = (x * rhs.x) + (y * rhs.y) + (z * rhs.z);
	return sum;
}

Vector Vector::operator*(double n)
{
	return Vector(n*x,n*y,n*z);
}

Vector Vector::operator^(const Vector & rhs)
{
	return Vector((y * rhs.z)-(z*rhs.y), (-x * rhs.z) + (z*rhs.x),( x * rhs.y) - (y*rhs.x));
}

double Vector::operator()(const Vector & a, const Vector & b)
{
	double vecSum = (x + a.x + b.x) + (y + a.y + b.y) + (z + a.z + b.z);
	return vecSum;
}

std::ostream & operator<<(std::ostream & out , const Vector & rhs )
{
	return out << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
}

std::istream & operator>>(std::istream & in, Vector & rhs)
{
	double x, y, z;
	std::cout << "Моля въведете стойност x на вектора: ";
	in >> x;
	std::cout << "Моля въведете стойност y на вектора: " ;
	in >> y;
	std::cout << "Моля въведете стойност z на вектора: " ;
	in >> z;

	rhs.x = x; rhs.y = y; rhs.z = z;
	return in;
}

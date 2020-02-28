#include "Tetrahedron.h"



Tetrahedron::Tetrahedron()
{
}

Tetrahedron::Tetrahedron( Point & a,  Point & b,  Point & c,  Point & d)//:A(a),B(b),C(c),D(d)
{
	try {
		if (a == b) {
			std::cout << "First " << a << " and ";
			std::cout << "second point " << b << std::endl;
			throw EqualPointException();

		}
		else if (a == c) {
			std::cout << "First " << a << " and ";
			std::cout << "third point " << c << std::endl;
			throw EqualPointException();
		}
		else if (b == c) {
			std::cout << "Second " << b << " and ";
			std::cout << "third point " << c << std::endl;
			throw EqualPointException();
		}
		else if (a == d) {
			std::cout << "First " << a << " and ";
			std::cout << "forth point " << d << std::endl;
			throw EqualPointException();
		}
		else if (b == d) {
			std::cout << "Second " << b << " and ";
			std::cout << "forth point " << d << std::endl;
			throw EqualPointException();
		}
		else if (c == d) {
			std::cout << "Third " << c << " and ";
			std::cout << "forth point " << d << std::endl;
			throw EqualPointException();
		}
		else {
			this->A = a;
			this->B = b;
			this->C = c;
			this->D = d;
		}

	}
	catch (EqualPointException& e)
	{
		std::cout << e.points() << std::endl;
	}
}

Tetrahedron::Tetrahedron(const Tetrahedron & rhs)
{
	A = rhs.A;
	B = rhs.B;
	C = rhs.C;
	D = rhs.D;
}

Tetrahedron & Tetrahedron::operator=(const Tetrahedron & rhs)
{
	if (this != &rhs)
	{
		A = rhs.A;
		B = rhs.B;
		C = rhs.C;
		D = rhs.D;
	}
	return *this;
}


Tetrahedron::~Tetrahedron()
{
}

bool Tetrahedron::regural() const
{
	Vector v1(A, B);
	Vector v2(A, C);
	Vector v3(B, C);
	Vector v4(A, D);
	Vector v5(B, D);
	Vector v6(C, D);

	double a = v1.length();
	double b = v2.length();
	double c = v3.length();
	double d = v4.length();
	double e = v4.length();
	double f = v4.length();

	if (a==b==c==d==e==f)	return true;
	return false;
}

double Tetrahedron::surroundingArea() const
{
	Vector v1(A, B);
	double a = v1.length();
	
	return sqrt(3 * (pow(a, 2)));;
}

std::ostream & operator<<(std::ostream & out, const Tetrahedron & rhs)
{
	return out << "Точка A:" << rhs.A << "Точка B:" << rhs.B << "Точка C:" << rhs.C<< "Точка D:"<< rhs.D;
}

std::istream & operator>>(std::istream & in, Tetrahedron & rhs)
{
	return in >> rhs.A >> rhs.B >> rhs.C >> rhs.D;
}

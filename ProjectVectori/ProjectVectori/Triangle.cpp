#include "Triangle.h"



Triangle::Triangle()
{
}


Triangle::Triangle(Point & a, Point & b, Point & c){
	try {
		if (a == b) {
			std::cout << "First " << a << " and ";
			std::cout << "second point " << b << std::endl;
			throw EqualPointException();

		}
		else if (a == c) {
			std::cout <<"First "<< a << " and ";
			std::cout << "third point " << c << std::endl;
			throw EqualPointException();
		}
		else if (b == c) {
			std::cout << "Second " << b <<" and ";
			std::cout << "third point " << c << std::endl;
			throw EqualPointException();
		}
		else {
			this->A = a;
			this->B = b;
			this->C = c;
		}

	}
	catch (EqualPointException& e)
	{
		std::cout << e.points() << std::endl;
	}
}


Triangle::~Triangle()
{
}

Triangle::Triangle(const Triangle & rhs)
{
	A = rhs.A;
	B = rhs.B;
	C = rhs.C;
}

Triangle & Triangle::operator=(const Triangle & rhs )
{
	if (this != &rhs)
	{
		A = rhs.A;
		B = rhs.B;
		C = rhs.C;
	}
	return *this;
}

void Triangle::triangleType()
{
	setlocale(LC_ALL, "Bulgarian");
	Vector v1(A, B);
	Vector v2(A, C);
	Vector v3(B, C);

	double A = v1.length();
    double B = v2.length();
    double C = v3.length();
 
    std::cout << "Видът на триъгълника е -> ";
    if (A == B == C)
    {
        std::cout << "равностранен\n";
    }
    if ((A == B && A != C && B != C) || (A == C && A != B && B != C) || (B == C && A != B && A != C))
    {
        std::cout << "равнобедрен\n";
    }
 
    double cosA, cosB, cosC;
 
    if (A>B && A>C){
        cosA = (pow(B, 2) + pow(C, 2) - pow(A, 2)) / 2 * B * C;
        if(cosA > 0) std::cout << "остроъгълен\n";
        if(cosA == 0) std::cout << "правоъгълен\n";
        if(cosA <  0) std::cout << "тъпоъгълен\n";
    }
    if (B>A && B>C){
        cosB = (pow(A, 2) + pow(C, 2) - pow(B, 2)) / 2 * A * C;
        if(cosB > 0) std::cout << "остроъгълен\n";//file<<"остроъгълен\n;
        if(cosB == 0) std::cout << "правоъгълен\n";
        if(cosB <  0) std::cout << "тъпоъгълен\n";
    }
    if (C>A && C>B) {
        cosC = (pow(A, 2) + pow(B, 2) - pow(C, 2)) / 2 * A * B;
        if (cosC > 0) std::cout << "остроъгълен\n";
        if (cosC == 0) std::cout << "правоъгълен\n";
        if (cosC <  0) std::cout << "тъпоъгълен\n";
    }
	/*double v1L = v1.length();
	double v2L = v2.length();
	double v3L = v3.length();
	if (v1L == v2L && v1L == v3L && v2L == v3L) {
		std::cout << "Това е равностранен триъгълник!";
	}
	else if (v1L == v2L || v1L == v3L || v2L == v3L) {
		std::cout << "Това е равнобедрен триъгълник!";
	}
	*/
}

double Triangle::perimeter(const Triangle & rhs) const
{
	Vector v1(A, B);
	Vector v2(A, C);
	Vector v3(B, C);

	return (v1.length() + v2.length() + v3.length());
}

double Triangle::perimeter() const
{
	Vector v1(A, B);
	Vector v2(A, C);
	Vector v3(B, C);

	return (v1.length() + v2.length() + v3.length());
}

double Triangle::area(const Triangle & rhs) const
{
	Vector v1(A, B) ;
	Vector v2(A, C);
	Vector v3(B, C);
	double a =v1.length();
	double b = v2.length();
	double c = v3.length();
	double p1 = perimeter(rhs) / 2;
	double res = sqrt(p1*(p1 - a)*(p1 - b)*(p1 - c));
	return res;
}

double Triangle::area() const
{
	Vector v1(A, B);
	Vector v2(A, C);
	Vector v3(B, C);

	double a = v1.length();
	double b = v2.length();
	double c = v3.length();
	double p1 = perimeter()/2;
	//p1/ 2;
	return sqrt(p1*(p1 - a)*(p1 - b)*(p1 - c));
}

Point Triangle::medicenter() const
{
	return Point((this->A.getX() + B.getX() + C.getX()) / 3,
		(this->A.getY() + B.getY() + C.getY()) / 3,
		(this->A.getZ() + B.getZ() + C.getZ()) / 3);
}

std::ostream & operator<<(std::ostream & out, const Triangle & rhs)
{
	return out << "Точка A:" << rhs.A << "Точка B:" << rhs.B << "Точка C:" << rhs.C;
}

std::istream & operator>>(std::istream & in, Triangle & rhs)
{
	return in >> rhs.A >> rhs.B >> rhs.C;
}

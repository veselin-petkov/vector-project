#include "EqualPointException.h"
#include "Segment.h"
class Tetrahedron :
	public Segment,public EqualPointException
{
public:
	Tetrahedron();
	Tetrahedron( Point &,  Point &,  Point &,  Point &);
	Tetrahedron(const Tetrahedron&);
	Tetrahedron & operator=(const Tetrahedron &);
	~Tetrahedron();

	bool regural()const;
	double surroundingArea() const;
public:
	Point A;
	Point B;
	Point C;
	Point D;

};
std::ostream& operator<< (std::ostream &, const Tetrahedron &);
std::istream& operator>> (std::istream &, Tetrahedron &);
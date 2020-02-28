#include "Segment.h"



Segment::Segment()
{
	x = 0;
	y = 0;
	z = 0;
	start = 0;
	end = 1;
}

Segment::Segment(const Segment & s)
{
	x = s.x;
	y = s.y;
	z = s.z;
	start = s.start;
	end = s.end;
}

Segment::Segment(const Line & l, double s , double e):Line(l),start(s),end(e)
{
	Start.x = startPoint.x + (l.x*s);
	Start.y = startPoint.y + (l.y*s);
	Start.z = startPoint.z + (l.z*s);

	End.x = startPoint.x + (l.x*e);
	End.y = startPoint.y + (l.y*e);
	End.z = startPoint.z + (l.z*e);
}


Segment::~Segment()
{
}

Segment & Segment::operator=(const Segment & rhs)
{
	if (this != &rhs)
	{
		Start = rhs.Start;
		End = rhs.End;
		end = rhs.end;
		start = rhs.start;
	}
	return *this;
}

double Segment::segmentLength()
{
	double d = sqrt(pow((End.x-Start.x),2)+ pow((End.y - Start.y), 2)+ pow((End.z - Start.z), 2));
	return d;
}

Point Segment::segmentMiddle()
{
	return Point((Start.x+End.x)/2, (Start.y + End.y) / 2, (Start.z + End.z) / 2);
}

bool operator==(const Point &, const Line &)
{
	return false;
}

std::istream & operator>>(std::istream & in, Segment & rhs)
{
	Point a;
	double s, e;
	in >> a;
	std::cout << "Моля въведете интервал. От:";
	in >> s;
	std::cout << "До:";
	in >> e;

	rhs.Start.x = rhs.startPoint.x + (rhs.x*s);
	rhs.Start.y = rhs.startPoint.y + (rhs.y*s);
	rhs.Start.z = rhs.startPoint.z + (rhs.z*s);

	rhs.End.x = rhs.startPoint.x + (rhs.x*e);
	rhs.End.y = rhs.startPoint.y + (rhs.y*e);
	rhs.End.z = rhs.startPoint.z + (rhs.z*e);

	return in;
}

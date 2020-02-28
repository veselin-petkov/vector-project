#pragma once
#include "Line.h"
class Segment :
	public Line
{
public:
	Segment();
	Segment(const Segment &);
	Segment(const Line& , double, double);
	~Segment();
	Segment & operator=(const Segment &);

	double segmentLength();
	Point segmentMiddle();
public:
	Point Start;
	Point End;
	double start, end;

};

bool operator==(const Point&,const Line &);
std::istream& operator>> (std::istream &, Segment &);

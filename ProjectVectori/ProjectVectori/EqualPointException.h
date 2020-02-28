#pragma once
#include <exception>
class EqualPointException : public std::exception
{
public:
	const char * points() const throw ();
};


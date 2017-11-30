
#include <stdio.h>
#include <unistd.h>
#include "PcompW.h"

namespace ai {

bool PcompW::operator() (const Point& a, const Point& b)
{
	return a.weight < b.weight;
}

};

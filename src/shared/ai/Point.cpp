
#include <stdio.h>
#include <unistd.h>
#include "Point.h"

namespace ai {

Point::Point (int x = 0, int y = 0, int w = 0)
{

}

Point Point::transform (Direction d)
{
	if(d == NORTH) this->x = x-1;
	else if(d == SOUTH) this->x = x+1;
	else if(d == EAST) this->y = y-1;
	else if(d == WEST) this->y = y+1;
	return this;
}
    
int Point::getX() const
{
	return this->x;
}

void Point::setX(int x)
{
	this->x = x;
}

int Point::getY() const
{
	return this->y;
}

void Point::setY(int y)
{
	this->y = y;
}

int Point::getWeight() const
{
	return this->weight;
}

void Point::setWeight(int weight)
{
	this->weight = weight;
}

};

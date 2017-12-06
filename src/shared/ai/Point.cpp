
#include <stdio.h>
#include <unistd.h>
#include "Point.h"

namespace ai {

Point::Point (int x, int y, int w)
{
    this->x = x;
    this->y = y;
    this->weight = w;
}

Point Point::transform (Direction d)
{
        Point point(this->getX(), this->getY(), this->getWeight() + 1);
	if(d == NORTH) point.x = x-1;
	else if(d == SOUTH) point.x = x+1;
	else if(d == EAST) point.y = y-1;
	else if(d == WEST) point.y = y+1;
	return point;
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

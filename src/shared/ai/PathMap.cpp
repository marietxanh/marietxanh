
#include <stdio.h>
#include <unistd.h>
#include "PathMap.h"

namespace ai {

PathMap::PathMap ()
{

}

int  PathMap::getWeight (const Point& p) const
{
	return p.getWeight();
}

void PathMap::setWeight (const Point& p)
{
	this->weights.push_back(p.getWeight());
}

const int* PathMap::getWeights () const
{
	//return this->weights.back();
}

void PathMap::init (status::ElementTab* grid)
{
	this->queue.push(Point{0,0,0});
	while(!this->queue.empty())
	{
		auto p = this->queue.top();
		this->queue.pop();
		for(Direction d = NORTH; d <= WEST; d = static_cast<Direction>(d+1))
		{
			auto pp = p.transform(d);
			if(grid->getElement(pp.getX(),pp.getY()) == NULL)
				pp.setWeight(p.getWeight() + 1);
			if(this->getWeight(pp) > pp.getWeight())
				this->queue.push(pp);
		}
	}
}

};

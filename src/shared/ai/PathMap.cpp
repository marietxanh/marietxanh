
#include <stdio.h>
#include <unistd.h>
#include "PathMap.h"

namespace ai {

PathMap::PathMap ()
{

}

int  PathMap::getWeight (const Point& p) const
{
	return p.weight;
}

void PathMap::setWeight (const Point& p)
{
	p.weight = this->weights;
}

const int* PathMap::getWeights () const
{
	return this->weights;
}

void PathMap::init (const status::ElementTab& grid)
{
	this->queue.push(Point{0,0,0});
	while(!this->queue.empty())
	{
		auto p = this->queue.top();
		this->queue.pop();
		for(Direction d : Direction)
		{
			auto pp = p.transform(d);
			if(grid.getElement(pp.x,pp.y) == NULL)
				pp.weight = p.weight + 1;
			if(getWeight(pp) > pp.weight)
				this->queue.push(pp);
		}
	}
}

};

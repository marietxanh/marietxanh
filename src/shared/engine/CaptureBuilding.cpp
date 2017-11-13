#include "CaptureBuilding.h"
#include <iostream>

using namespace engine;
using namespace status;

CaptureBuilding::CaptureBuilding (int height, int width)
{
	this->height = height;
	this->width = width;
}
CommandTypeID CaptureBuilding::getTypeID () const
{
	return CAPTURE;
}
void CaptureBuilding::execute (status::State& state)
{
	((Building*)(state.getBuildings()->getElement(height, width)))->setHealth(- ((Unit*)(state.getUnits()->getElement(height, width)))->getHealth());
	if(((Building*)(state.getBuildings()->getElement(height, width)))->getHealth() <= 0)
	{
		(Building*)(state.getBuildings()->getElement(height, width)))->setHealth(20);
		cout << "Building captured !" << endl;
	}
	else
		std::cout << "Health remaining : " << ((Building*)(state.getBuildings()->getElement(height, width)))->getHealth() << endl;
}

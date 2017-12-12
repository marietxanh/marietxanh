#include "../status.h"
#include "CaptureBuilding.h"
#include <iostream>

using namespace status;

namespace engine {

	CaptureBuilding::CaptureBuilding (int height, int width)
	{
		this->height = height;
		this->width = width;
	}
	
	CaptureBuilding::~CaptureBuilding()
	{
	
	}
	
	CommandTypeID CaptureBuilding::getTypeID () const
	{
		return CAPTURE;
	}
	void CaptureBuilding::execute (std::stack<Action*>& actions, status::State* state)
	{
            if(((Building*)(state->getBuildings()->getElement(height, width)))->getTeam() != ((Unit*)(state->getUnits()->getElement(height, width)))->getTeam())
            {
		((Building*)(state->getBuildings()->getElement(height, width)))->setHealth(- ((Unit*)(state->getUnits()->getElement(height, width)))->getHealth());
		if(((Building*)(state->getBuildings()->getElement(height, width)))->getHealth() <= 0)
		{
			((Building*)(state->getBuildings()->getElement(height, width)))->setHealth(20);
			std::cout << "Building captured !" << std::endl;
		}
		else
			std::cout << "Health remaining : " << ((Building*)(state->getBuildings()->getElement(height, width)))->getHealth() << std::endl;
            }
	}
        void CaptureBuilding::serialize (Json::Value& out) const
        {
            
        }
        CaptureBuilding* CaptureBuilding::deserialize (const Json::Value& in)
        {
            
        }
	
};

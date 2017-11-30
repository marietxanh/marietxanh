#include <stdio.h>
#include <unistd.h>
#include "HeuristicAI.h"

namespace ai {

HeuristicAI::HeuristicAI ()
{

}

const PathMap&  HeuristicAI::getAdvUnitsMap () const
{
	return this->adv_units_map;
}

const PathMap&  HeuristicAI::getBuildingMap () const
{
	return this->building_map;
}

void HeuristicAI::run (engine::Engine* engine)
{
	/* on prend la même fonction que dans random AI */
		int height = engine->getState()->getHeight();
		int width = engine->getState()->getWidth();
		for(int i(0); i < height; i++)
		{
			for(int j(0); j < width; j++)
			{
				if(engine->getState()->getUnits()->getElement(i,j) != NULL)
				{
					engine->addCommand(this->getCommand(i, j, height, width));
					engine->update();
				}
			}
		}
}

};

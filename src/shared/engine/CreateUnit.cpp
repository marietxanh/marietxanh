#include "CreateUnit.h"
#include "CreateUnitAction.h"
#include "../status.h"
#include <iostream>

using namespace status;

namespace engine {

	CreateUnit::CreateUnit (status::TypeUnits type_unit, int height, int width)
	{
		this->type_unit = type_unit;
		this->height = height;
		this->width = width;
	}
	
	CreateUnit::~CreateUnit()
	{
	
	}
	
	CommandTypeID CreateUnit::getTypeID () const
	{
		return CREATE;
	}
	void CreateUnit::execute (std::stack<Action*>& actions, status::State* state)
	{
            CreateUnitAction* create_unit = NULL;
            if (state->getBuildings()->getElement(height, width) != NULL)
            {
		state->getUnits()->newElement(height, width, new Unit(type_unit, ((Building*)(state->getBuildings()->getElement(height, width)))->getTeam()));
		std::cout << "Unit created in (" << height << ", " << width << ")" << std::endl;
                //create_unit->setElement(state->getUnits()->getElement(height, width));
                actions.push(create_unit);
            }
	}
        void CreateUnit::serialize (Json::Value& out) const
        {
            
        }
        CreateUnit* CreateUnit::deserialize (const Json::Value& in)
        {
            
        }
	
};

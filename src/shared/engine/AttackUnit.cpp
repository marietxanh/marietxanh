#include "AttackUnit.h"
#include <iostream>

using namespace engine;
using namespace status;

namespace engine {

	AttackUnit::AttackUnit(int height_shooter, int width_shooter, int height_target, int width_target)
	{
		this->height_shooter = height_shooter;
		this->width_shooter = width_shooter;
		this->height_target = height_target;
		this->width_target = width_target;
	}

	AttackUnit::~AttackUnit()
	{
	
	}
	
	CommandTypeID AttackUnit::getTypeID () const
	{
		return ATTACK;
	}

	void AttackUnit::execute (status::State* state)
	{
            if(state->getUnits()->getElement(height_target, width_target) != NULL)
            {
                if(((Unit*)(state->getUnits()->getElement(height_shooter, width_shooter)))->getTeam() != ((Unit*)(state->getUnits()->getElement(height_target, width_target)))->getTeam())
                {
                    std::cout << "execute attack" << std::endl;
                    int attack = ((Unit*)(state->getUnits()->getElement(height_shooter, width_shooter)))->getAttack();
                    ((Unit*)(state->getUnits()->getElement(height_target, width_target)))->setHealth(-attack); 
                    std::cout << "Unit from (" << height_shooter << ", " << width_shooter << ") attack unit in (" << height_target << ", " << width_target << ")" << std::endl;
                    std::cout << "Health of attacked unit : " << ((Unit*)(state->getUnits()->getElement(height_target, width_target)))->getHealth() << std::endl;
                }
                else std::cout << "Units are same team" << std::endl;
            }
            else std::cout << "No target in (" << height_target << ", " << width_target << ")\n" << std::endl;
	}

};

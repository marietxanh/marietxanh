#include "AttackUnit.h"
#include <iostream>

using namespace engine;
using namespace status;

AttackUnit::AttackUnit(int height_shooter, int width_shooter, int height_target, int width_target)
{
	this->height_shooter = height_shooter;
	this->width_shooter = width_shooter;
	this->height_target = height_target;
	this->width_target = width_target;
}

CommandTypeID AttackUnit::getTypeID () const
{
	return ATTACK;
}

void execute (status::State& state)
{
	int attack = ((Unit*)(state.getUnits()->getElement(height_shooter, width_shooter)))->getAttack();
    ((Unit*)(state.getUnits()->getElement(height_target, width_target)))->setHealth(-attack); 
    std::cout << "Unit from (" << height_shooter << ", " << width_shooter << ") attack unit in (" << height_target << ", " << width_target << ")" << std::endl;
    std::cout << "Health of attacked unit : " << ((Unit*)(state.getUnits()->getElement(height_target, width_target)))->getHealth() << std::endl;
}

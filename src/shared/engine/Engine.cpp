/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <map>
#include <memory>
#include <iostream>
#include "../status.h"
#include "Engine.h"

using namespace engine;
using namespace status;

Engine::Engine (std::string& file_name)
{
    this->state = new State(file_name);
}
Engine::~Engine ()
{
    delete state;
}

void Engine::createUnit (TypeUnits type_unit, int height, int width)
{
    
    state->getUnits()->setElement(height, width, new Unit(type_unit));
    std::cout << "Unit created in (" << height << ", " << width << ")" << std::endl;
}

void Engine::moveUnit (int height_start, int width_start, int height_end, int width_end)
{
    this->state->getUnits()->setElement(height_end, width_end, state->getUnits()->getElement(height_start, width_start));
    std::cout << "Move units from (" << height_start << ", " << width_start << ") to (" << height_end << ", " << width_end << ")" << std::endl;
    this->state->getUnits()->setElement(height_start, width_start, NULL);
}

void Engine::attackUnit (int height_shooter, int width_shooter, int height_target, int width_target)
{
    int attack = ((Unit*)(this->state->getUnits()->getElement(height_shooter, width_shooter)))->getAttack();
    ((Unit*)(this->state->getUnits()->getElement(height_target, width_target)))->setHealth(-attack); 
    std::cout << "Unit from (" << height_shooter << ", " << width_shooter << ") attack unit in (" << height_target << ", " << width_target << ")" << std::endl;
    std::cout << "Health of attacked unit : " << ((Unit*)(this->state->getUnits()->getElement(height_target, width_target)))->getHealth() << std::endl;
}

void Engine::captureBuilding (int height, int width)
{
    ((Building*)(this->state->getBuildings()->getElement(height, width)))->setHealth(- ((Unit*)(this->state->getUnits()->getElement(height, width)))->getHealth());
}

status::State* Engine::getState () const
{
    return this->state;
}
void Engine::setState (status::State* new_state)
{
    this->state = new_state;
}

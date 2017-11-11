/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <map>
#include <memory>
#include "Engine.h"
#include "status/Unit.h"
#include "status/TypeTransport.h"
#include "status.h"
#include "status/Building.h"
#include "../status.h"

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
}

void Engine::moveUnit (int height_start, int width_start, int height_end, int width_end)
{
    this->state->getUnits()->setElement(height_end, width_end, state->getUnits()->getElement(height_start, width_start));
    this->state->getUnits()->setElement(height_start, width_end, NULL);
}

void Engine::attackUnit (int height_shooter, int width_shooter, int height_target, int width_target)
{
    ((Unit*)(this->state->getUnits()->getElement(height_target, width_target)))->setHealth(- ((Unit*)(this->state->getUnits()->getElement(height_shooter, width_shooter)))->getAttack());  
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

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "CreateUnitAction.h"

using namespace status;

namespace engine {
    
CreateUnitAction::CreateUnitAction (status::TypeUnits type_unit, int height, int width)
{
    
}

void CreateUnitAction::apply (status::State* state)
{
    
}

void CreateUnitAction::undo (status::State* state)
{
    
}

void CreateUnitAction::setElement (status::Element* element)
{
    
}

// Setters and Getters
const status::TypeUnits& CreateUnitAction::getType_unit() const
{
    return this->type_unit;
}

void CreateUnitAction::setType_unit(const status::TypeUnits& type_unit)
{
    this->type_unit = type_unit;
}

int CreateUnitAction::getHeight() const
{
    return this->height;
}

void CreateUnitAction::setHeight(int height)
{
    this->height = height;
}

int CreateUnitAction::getWidth() const
{
    return this->width;
}

void CreateUnitAction::setWidth(int width)
{
    this->width = width;
}
    
};

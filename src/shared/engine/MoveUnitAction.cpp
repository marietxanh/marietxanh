/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "MoveUnitAction.h"

using namespace status;

namespace engine {
    
MoveUnitAction::MoveUnitAction (int height_start, int width_start, int height_end, int width_end)
{
    
}

void MoveUnitAction::apply (status::State* state)
{
    
}

void MoveUnitAction::undo (status::State* state)
{
    
}

void MoveUnitAction::setElement (status::Element* element)
{
    
}


// Setters and Getters
int MoveUnitAction::getHeight_start() const
{
    return this->height_start;
}

void MoveUnitAction::setHeight_start(int height_start)
{
    this->height_start = height_start;
}

int MoveUnitAction::getWidth_start() const
{
    return this->width_start;
}

void MoveUnitAction::setWidth_start(int width_start)
{
    this->width_start = width_start;
}

int MoveUnitAction::getHeight_end() const
{
    return this->height_end;
}

void MoveUnitAction::setHeight_end(int height_end)
{
    this->height_end = height_end;
}

int MoveUnitAction::getWidth_end() const
{
    return this->width_end;
}

void MoveUnitAction::setWidth_end(int width_end)
{
    this->width_end = width_end;
}
    
};


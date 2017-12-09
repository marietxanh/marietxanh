/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "ResetUnitsAction.h"

using namespace status;

namespace engine {

ResetUnitsAction::ResetUnitsAction (status::Element* element)
{
    this->prev_unit = element;
}

void ResetUnitsAction::apply (status::State* state)
{
    
}

void ResetUnitsAction::undo (status::State* state)
{
    
}
    
};


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "MoveCharCommand.h"

using namespace status;

MoveCharCommand::MoveCharCommand()
{
    
}

MoveCharCommand::MoveCharCommand (ElementTab* unit_tab, Land* destination, Unit* unit_to_move){
    int height_end = destination->getHeight_position();
    int width_end = destination->getWidth_position();
    int height_start = unit_to_move->getHeight_position();
    int width_start = unit_to_move->getWidth_position();
    if(unit_tab->getElement(height_end, width_end) == NULL)
    {
        unit_tab->setElement(height_end, width_end, unit_to_move);
        unit_tab->getElement(height_start, width_start) = NULL;
        std::cout << "Unit moved from (" <<
                height_start << ", " << width_start << ") to (" <<
                height_end << ", " << width_end << ")" << std::endl;
    }
}

MoveCharCommand::~MoveCharCommand()
{
    
}

CommandTypeId MoveCharCommand::getTypeId () const
{
    return MOVE_CHAR;
}


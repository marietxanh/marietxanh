/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CreateCharacterCommand.h"
#include "status/Unit.h"

using namespace engine;
using namespace status;

CreateCharacterCommand::CreateCharacterCommand()
{
    
}

CreateCharacterCommand::CreateCharacterCommand(Building* factory, ElementTab* units_tab)
{
    int height = factory->getHeight_position();
    int width = factory->getWidth_position();
    if(units_tab->getElement(height, width) == NULL)
    {
        units_tab->setElement(height, width, new Unit(INFANTRY));
        std::cout << "New unit created in : (" << height << ", " << width << << ")" << std::endl;
    }
}

CreateCharacterCommand::~CreateCharacterCommand()
{
    
}

CommandTypeId CreateCharacterCommand::getTypeId() const
{
    return CREATE_CHARACTER;
}



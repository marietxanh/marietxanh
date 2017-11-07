/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "../status/Building.h"
using namespace status;

Building::Building(TypeBuilding type_building) : Land(BUILDING)
{
    this->health = 20;
    this->type_building = type_building;
}

Building::~Building()
{
    
}
 
bool Building::canCraft() const
{
    bool answer = false;
    if ((this->getType_building() != TOWN) && (this->getType_building() != HQ)) answer = true;
    return answer;
}

int Building::getHealth() const
{
    return this->health;
}

TypeBuilding Building::getType_building() const
{
    return this->type_building;
}
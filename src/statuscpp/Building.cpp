/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "../status/Building.h"
using namespace status;

Building::Building(int abs, int ord, TypeBuilding type_building, TypeLand type_land, TypeID type_id) : Land(abs, ord, type_land, type_id)
{
    this->health = 20;
    this->type_building = type_building;
}
 
bool const Building::canCraft()
{
    bool answer = false;
    if (this->getType_building() != TOWN && this->getType_building() != HQ ) answer = true;
    return answer;
}

int const Building::getHealth()
{
    return this->health;
}
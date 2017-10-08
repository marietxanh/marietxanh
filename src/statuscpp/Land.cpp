/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "../status/Land.h"
using namespace status;

Land::Land(int abs, int ord, TypeLand type_land, TypeID type_id): Element(abs, ord, type_id)
{
    this->type_land = type_land;
}

bool const Land::isBuilding()
{
    bool answer = false;
    if (this->getType_land() != BUILDING) return answer;
    else
    {
        answer = true;
        return answer;
    }
}

Land::~Land ()
{

}

bool const Land::isStatic()
{
    bool answer = false;
    if(getType_id() != LAND) answer = true;
    return answer;
}

int Land::getDefense() const
{
    return this->defense;
}
    
void Land::setDefense(int defense)
{
    this->defense = defense;
}

int Land::getCost_mvmt() const
{
    return this->cost_mvmt;
}

void Land::setCost_mvmt(int cost_mvmt)
{
    this->cost_mvmt = cost_mvmt;
}

TypeLand Land::getType_land() const{
    return this->type_land;
}
void Land::setType_land(TypeLand type_land){
    this->type_land = type_land;
}
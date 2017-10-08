/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "../status/Land.h"

Element::Land(int abs, int ord, int type) : abscissa(abs), ordinate(ord), type_land(type)
{
    this->unit& = NULL;
}

bool const Land::isBuilding()
{
    bool answer = false;
    if (this->getTypeLand() != BUILDING) return answer;
    else
    {
        answer = true;
        return answer;
    }
}

bool const Land::hasUnit()
{
    bool answer = false;
    if(unit& == NULL) return answer;
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
     if(getTypeID() != LAND) return answer;
     else
     {
         answer = true;
         return answer;
     }
    
int Land::getDefense() const
{
    return this->defense;
}
    
void Land :setDefense(int defense)
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
const Unit& getUnit() const{
    return this->unit;
}

void setUnit(const Unit& unit){
    this->unit = unit
}
TypeLand getType_land() const{
    return this->type_land;
}
void setType_land(TypeLand type_land){
    this->type_land = type_land;
}
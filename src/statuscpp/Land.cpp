/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "../status/Unit.h"
#include "../status/Land.h"

Element :: Land (int abscissa, int ordinate, int type) : this->abscissa(abscissa), this->ordinate(ordinate), this->type(type)
{
  
}

bool const Land :: isBuilding ()
{
    bool answer = false;
    if (this->getTypeLand() == 0)
        answer = true;
    return answer;
}

bool Land :: hasUnit ( )
{

}

Land :: ~Land ()
{

}

TypeLand const Land :: getTypeLand ()
{
    return type_land;
}

void Land :: setTypeLand (TypeLand type)
{
    this->type_land = type;
}

/* bool const Land :: isStatic ()
{
     bool answer = false;
     TypeID typeElement = this->getType_ID();
     if (typeElement == 0)
         answer = true;
     return answer;
} */

bool const Land :: isLand ()
{
    return true;
}
    
int Land :: getDefense() const
{
    return this->defense;
}
    
void Land :: setDefense(int defense)
{
    this->defense = defense;
}

int Land :: getCost_mvmt() const
{
    return this->cost_mvmt;
}

void Land :: setCost_mvmt(int cost_mvmt)
{
    this->cost_mvmt = cost_mvmt;
}

const Element*& Land :: getUnit() const
{

}

void Land :: setUnit(const Element*& unit)
{
    
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "../status/Land.h"
#include "../status/Building.h"

Land :: Building (int type)
{

}
 
bool Building :: canCraft ()
{
    bool answer = false;
    if (this->getTypeBuilding() == 1 )
        answer = true;
    return answer;
}

bool const Building :: isLand ()
{
     bool answer = false;
    if (this->getTypeLand() == 1 )
        answer = true;
    return answer;
}

bool const Building :: canProvide ()
{
    bool answer = false;
    if (this->getTypeBuilding() == 1 )
        answer = true;
    return answer;
}
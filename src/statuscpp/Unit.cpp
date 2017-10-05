/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "../status/Unit.h"
#include "../status/Element.h"

Element :: Unit (bool land, bool mountain, bool river, bool sea, int health) : this->health(health)
{

}

 bool Unit :: canAtk (Unit* target)
 {
     bool answer = false;
     TypeUnit target_type = target.getTypeUnit();
      
     if (this->attack == 0)
         answer = false;
     
     return answer;       
 }
 
 bool Unit :: canCross (Element* land)
 {
     bool answer = false;
     type_unit unite = this->getTypeUnit();
     type_land terrain = land.getTypeLand();
     
     return answer;
 }
 
 bool Unit :: canCapture (Element* land)
 {
     bool answer = false;
     type_land terrain = land.getTypeLand();
     
     return answer;
 }
 
 TypeUnit const Unit :: getTypeUnit ()
 {
     return type_unit;
 }
 
 void Unit :: setTypeUnit (TypeUnit type)
 {
     this->type_unit = type;
 }
 
 /* bool const Unit :: isStatic ()
 {
     bool answer = false;
     TypeID typeElement = this->getType_ID();
     if (typeElement == 0)
         answer = true;
     return answer;
 } */
    
 bool const Unit :: isTransport ()
{
    bool answer = false;
     type_unit unite = this->getTypeUnit();
     if (unite == 0)
         answer = true;
     return answer;
}
    
 bool const Unit :: canGroup ()
 {
     bool answer = false;
     type_unit unite = this->getTypeUnit();
     if (unite == 1)
         answer = true;
     return answer;
 }
 
int Unit :: getAmplitude_mvmt() const
{
    return this->amplitude_mvmt;
}

void Unit :: setAmplitude_mvmt(int amplitude_mvmt)
{
    this->amplitude_mvmt = amplitude_mvmt;
}

int Unit :: getRange_mvmt() const
{
    return this->range_mvmt;
}

void Unit :: setRange_mvmt(int range_mvmt)
{
    this->range_mvmt = range_mvmt;
}

int Unit :: getFuel_tank() const
{
    return this->fuel_tank;
}

void Unit :: setFuel_tank(int fuel_tank)
{
    this->fuel_tank = fuel_tank;
}

int Unit :: getFuel_consumption() const
{
    return this->fuel_consumption;
}

void Unit :: setFuel_consumption(int fuel_consumption)
{
    this->fuel_consumption = fuel_consumption;
}

int Unit :: getRocket() const
{
    return this->rocket;
}

void Unit :: setRocket(int rocket)
{
    this->rocket = rocket;
}

int Unit :: getAttack() const
{
    return this->attack;
}

void Unit :: setAttack(int attack)
{
    this->attack = attack;
}

int Unit :: getHealth() const
{
    return this->health;
}

void Unit :: setHealth(int health)
{
    this->health = health;
}
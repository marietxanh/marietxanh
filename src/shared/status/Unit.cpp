/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../status/Unit.h"
using namespace status;

Unit::Unit(int abs, int ord, TypeUnits type_units): Element(abs, ord, UNIT)
{
    this->type_unit = type_units;
}
 
 TypeUnits const Unit :: getTypeUnit ()
 {
     return type_unit;
 }
 
 void Unit :: setTypeUnit (TypeUnits type)
 {
     this->type_unit = type;
 }
 
bool const Unit::isStatic()
 {
    return false;
 }
    
bool const Unit::isTransport()
{
    bool answer = false;
    if (this->getType_unit() == TRANSPORT) answer = true;
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
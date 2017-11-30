/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../status/Unit.h"
#include <iostream>
using namespace std;

namespace status{
    
    Unit::Unit(TypeUnits type_units, TEAM team): Element(UNIT)
    {
        this->type_unit = type_units;
        this->team = team;
        this->attack = 2;
        this->health = 10;
        this->turn_attack = false;
        this->turn_move = false;
        this->range_mvmt = 1;
        this->amplitude_mvmt = 3;
        if(type_unit == ANTI_AIR_TANK || type_unit == ANTI_AIR_ML || type_unit == ARTILLERY || type_unit == ROCKET_L)
        {
            this->double_action = false;
        }
        else this->double_action = true;
    }

    void Unit::affiche() const
    {
        cout << "Ceci est une unité." << endl;
    }

     TypeUnits Unit :: getType_unit () const
     {
         return type_unit;
     }

     void Unit :: setTypeUnit (TypeUnits type)
     {
         this->type_unit = type;
     }

    bool Unit::isStatic() const
     {
        return false;
     }

    bool Unit::isTransport() const
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
        this->health += health;
        if(this->health > 10) this->health = 10;
    }

    TEAM Unit::getTeam() const
    {
        return this->team;
    }
    void Unit::setTeam(TEAM team)
    {
        this->team = team;
    }

    bool Unit::getTurn_attack() const
    {
        return turn_attack;
    }
    void Unit::setTurn_attack(bool turn_attack)
    {
        this->turn_attack = turn_attack;
    }
    bool Unit::getTurn_move() const
    {
        return turn_move;
    }
    void Unit::setTurn_move(bool turn_move)
    {
        this->turn_move = turn_move;
    }
    bool Unit::getDouble_action() const
    {
        return double_action;
    }
    void Unit::setDouble_action(bool double_action)
    {
        this->double_action = double_action;
    }

};
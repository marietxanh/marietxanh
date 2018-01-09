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
        this->health = 10;
        this->turn_attack = false;
        this->turn_move = false;
        this->range_shoot = 1;
        this->amplitude_mvmt = 3;
        this->basic_units_damage.resize(14);
        this->basic_transports_damage.resize(4);
        if(type_unit == ANTI_AIR_TANK || type_unit == ANTI_AIR_ML || type_unit == ARTILLERY || type_unit == ROCKET_L)
        {
            this->double_action = false;
        }
        else this->double_action = true;
        switch(type_units){
            case TRANSPORT:
                break;
            case INFANTRY:
                basic_units_damage[TRANSPORT] = -1;
                basic_units_damage[INFANTRY] = 55;
                basic_units_damage[MECH] = 45;
                basic_units_damage[RECON] = 12;
                basic_units_damage[TANK] = 5;
                basic_units_damage[TANK_M] = 1;
                basic_units_damage[ANTI_AIR_TANK] = 5;
                basic_units_damage[ANTI_AIR_ML] = 25;
                basic_units_damage[ARTILLERY] = 15;
                basic_units_damage[ROCKET_L] = 25;
                basic_units_damage[FIGHTER] = 0;
                basic_units_damage[BOMBER] = 0;
                basic_units_damage[DESTROYER] = 0;
                basic_units_damage[HELICOPTER] = 7;
                basic_transports_damage[0] = 0;
                basic_transports_damage[1] = 15;
                basic_transports_damage[2] = 30;
                basic_transports_damage[3] = 0;
                break;
            case MECH:
                basic_units_damage[TRANSPORT] = -1;
                basic_units_damage[INFANTRY] = 65;
                basic_units_damage[MECH] = 55;
                basic_units_damage[RECON] = 85;
                basic_units_damage[TANK] = 55;
                basic_units_damage[TANK_M] = 15;
                basic_units_damage[ANTI_AIR_TANK] = 65;
                basic_units_damage[ANTI_AIR_ML] = 85;
                basic_units_damage[ARTILLERY] = 70;
                basic_units_damage[ROCKET_L] = 85;
                basic_units_damage[FIGHTER] = 0;
                basic_units_damage[BOMBER] = 0;
                basic_units_damage[DESTROYER] = 0;
                basic_units_damage[HELICOPTER] = 9;
                basic_transports_damage[0] = 0;
                basic_transports_damage[1] = 75;
                basic_transports_damage[2] = 35;
                basic_transports_damage[3] = 0;
                break;
            case RECON:
                basic_units_damage[TRANSPORT] = -1;
                basic_units_damage[INFANTRY] = 70;
                basic_units_damage[MECH] = 65;
                basic_units_damage[RECON] = 35;
                basic_units_damage[TANK] = 6;
                basic_units_damage[TANK_M] = 1;
                basic_units_damage[ANTI_AIR_TANK] = 4;
                basic_units_damage[ANTI_AIR_ML] = 28;
                basic_units_damage[ARTILLERY] = 45;
                basic_units_damage[ROCKET_L] = 55;
                basic_units_damage[FIGHTER] = 0;
                basic_units_damage[BOMBER] = 0;
                basic_units_damage[DESTROYER] = 0;
                basic_units_damage[HELICOPTER] = 10;
                basic_transports_damage[0] = 0;
                basic_transports_damage[1] = 45;
                basic_transports_damage[2] = 30;
                basic_transports_damage[3] = 0;;
                break;
            case TANK:
                basic_units_damage[TRANSPORT] = -1;
                basic_units_damage[INFANTRY] = 75;
                basic_units_damage[MECH] = 70;
                basic_units_damage[RECON] = 85;
                basic_units_damage[TANK] = 55;
                basic_units_damage[TANK_M] = 15;
                basic_units_damage[ANTI_AIR_TANK] = 5;
                basic_units_damage[ANTI_AIR_ML] = 25;
                basic_units_damage[ARTILLERY] = 15;
                basic_units_damage[ROCKET_L] = 25;
                basic_units_damage[FIGHTER] = 0;
                basic_units_damage[BOMBER] = 0;
                basic_units_damage[DESTROYER] = 10;
                basic_units_damage[HELICOPTER] = 10;
                basic_transports_damage[0] = 10;
                basic_transports_damage[1] = 75;
                basic_transports_damage[2] = 40;
                basic_transports_damage[3] = 5;
                break;
            case TANK_M:
                basic_units_damage[TRANSPORT] = -1;
                basic_units_damage[INFANTRY] = 105;
                basic_units_damage[MECH] = 95;
                basic_units_damage[RECON] = 105;
                basic_units_damage[TANK] = 85;
                basic_units_damage[TANK_M] = 55;
                basic_units_damage[ANTI_AIR_TANK] = 105;
                basic_units_damage[ANTI_AIR_ML] = 105;
                basic_units_damage[ARTILLERY] = 105;
                basic_units_damage[ROCKET_L] = 105;
                basic_units_damage[FIGHTER] = 0;
                basic_units_damage[BOMBER] = 0;
                basic_units_damage[DESTROYER] = 10;
                basic_units_damage[HELICOPTER] = 12;
                basic_transports_damage[0] = 35;
                basic_transports_damage[1] = 105;
                basic_transports_damage[2] = 45;
                basic_transports_damage[3] = 55;
                break;
            case ANTI_AIR_TANK:
                basic_units_damage[TRANSPORT] = -1;
                basic_units_damage[INFANTRY] = 105;
                basic_units_damage[MECH] = 105;
                basic_units_damage[RECON] = 60;
                basic_units_damage[TANK] = 25;
                basic_units_damage[TANK_M] = 10;
                basic_units_damage[ANTI_AIR_TANK] = 45;
                basic_units_damage[ANTI_AIR_ML] = 55;
                basic_units_damage[ARTILLERY] = 50;
                basic_units_damage[ROCKET_L] = 55;
                basic_units_damage[FIGHTER] = 65;
                basic_units_damage[BOMBER] = 75;
                basic_units_damage[DESTROYER] = 0;
                basic_units_damage[HELICOPTER] = 120;
                basic_transports_damage[0] = 0;
                basic_transports_damage[1] = 50;
                basic_transports_damage[2] = 120;
                basic_transports_damage[3] = 0;
                break;
            case ANTI_AIR_ML:
                basic_units_damage[TRANSPORT] = -1;
                basic_units_damage[INFANTRY] = 0;
                basic_units_damage[MECH] = 0;
                basic_units_damage[RECON] = 0;
                basic_units_damage[TANK] = 0;
                basic_units_damage[TANK_M] = 0;
                basic_units_damage[ANTI_AIR_TANK] = 0;
                basic_units_damage[ANTI_AIR_ML] = 0;
                basic_units_damage[ARTILLERY] = 0;
                basic_units_damage[ROCKET_L] = 0;
                basic_units_damage[FIGHTER] = 100;
                basic_units_damage[BOMBER] = 100;
                basic_units_damage[DESTROYER] = 0;
                basic_units_damage[HELICOPTER] = 120;
                basic_transports_damage[0] = 0;
                basic_transports_damage[1] = 0;
                basic_transports_damage[2] = 120;
                basic_transports_damage[3] = 0;
                break;
            case ARTILLERY:
                basic_units_damage[TRANSPORT] = -1;
                basic_units_damage[INFANTRY] = 90;
                basic_units_damage[MECH] = 85;
                basic_units_damage[RECON] = 80;
                basic_units_damage[TANK] = 70;
                basic_units_damage[TANK_M] = 45;
                basic_units_damage[ANTI_AIR_TANK] = 75;
                basic_units_damage[ANTI_AIR_ML] = 80;
                basic_units_damage[ARTILLERY] = 75;
                basic_units_damage[ROCKET_L] = 80;
                basic_units_damage[FIGHTER] = 0;
                basic_units_damage[BOMBER] = 0;
                basic_units_damage[DESTROYER] = 40;
                basic_units_damage[HELICOPTER] = 0;
                basic_transports_damage[0] = 55;
                basic_transports_damage[1] = 70;
                basic_transports_damage[2] = 0;
                basic_transports_damage[3] = 65;
                break;
            case ROCKET_L:
                basic_units_damage[TRANSPORT] = -1;
                basic_units_damage[INFANTRY] = 95;
                basic_units_damage[MECH] = 90;
                basic_units_damage[RECON] = 90;
                basic_units_damage[TANK] = 80;
                basic_units_damage[TANK_M] = 55;
                basic_units_damage[ANTI_AIR_TANK] = 85;
                basic_units_damage[ANTI_AIR_ML] = 90;
                basic_units_damage[ARTILLERY] = 80;
                basic_units_damage[ROCKET_L] = 85;
                basic_units_damage[FIGHTER] = 0;
                basic_units_damage[BOMBER] = 0;
                basic_units_damage[DESTROYER] = 55;
                basic_units_damage[HELICOPTER] = 0;
                basic_transports_damage[0] = 60;
                basic_transports_damage[1] = 80;
                basic_transports_damage[2] = 0;
                basic_transports_damage[3] = 85;
                break;
            case FIGHTER:
                basic_units_damage[TRANSPORT] = -1;
                basic_units_damage[INFANTRY] = 0;
                basic_units_damage[MECH] = 0;
                basic_units_damage[RECON] = 0;
                basic_units_damage[TANK] = 0;
                basic_units_damage[TANK_M] = 0;
                basic_units_damage[ANTI_AIR_TANK] = 0;
                basic_units_damage[ANTI_AIR_ML] = 0;
                basic_units_damage[ARTILLERY] = 0;
                basic_units_damage[ROCKET_L] = 0;
                basic_units_damage[FIGHTER] = 55;
                basic_units_damage[BOMBER] = 100;
                basic_units_damage[DESTROYER] = 0;
                basic_units_damage[HELICOPTER] = 100;
                basic_transports_damage[0] = 0;
                basic_transports_damage[1] = 0;
                basic_transports_damage[2] = 100;
                basic_transports_damage[3] = 0;
                break;
            case BOMBER:
                basic_units_damage[TRANSPORT] = -1;
                basic_units_damage[INFANTRY] = 110;
                basic_units_damage[MECH] = 110;
                basic_units_damage[RECON] = 105;
                basic_units_damage[TANK] = 105;
                basic_units_damage[TANK_M] = 95;
                basic_units_damage[ANTI_AIR_TANK] = 95;
                basic_units_damage[ANTI_AIR_ML] = 105;
                basic_units_damage[ARTILLERY] = 105;
                basic_units_damage[ROCKET_L] = 105;
                basic_units_damage[FIGHTER] = 0;
                basic_units_damage[BOMBER] = 0;
                basic_units_damage[DESTROYER] = 75;
                basic_units_damage[HELICOPTER] = 0;
                basic_transports_damage[0] = 95;
                basic_transports_damage[1] = 105;
                basic_transports_damage[2] = 0;
                basic_transports_damage[3] = 85;
                break;
            case DESTROYER:
                basic_units_damage[TRANSPORT] = -1;
                basic_units_damage[INFANTRY] = 95;
                basic_units_damage[MECH] = 90;
                basic_units_damage[RECON] = 90;
                basic_units_damage[TANK] = 80;
                basic_units_damage[TANK_M] = 55;
                basic_units_damage[ANTI_AIR_TANK] = 85;
                basic_units_damage[ANTI_AIR_ML] = 90;
                basic_units_damage[ARTILLERY] = 80;
                basic_units_damage[ROCKET_L] = 85;
                basic_units_damage[FIGHTER] = 0;
                basic_units_damage[BOMBER] = 0;
                basic_units_damage[DESTROYER] = 50;
                basic_units_damage[HELICOPTER] = 0;
                basic_transports_damage[0] = 95;
                basic_transports_damage[1] = 80;
                basic_transports_damage[2] = 0;
                basic_transports_damage[3] = 95;
                break;
            case HELICOPTER:
                basic_units_damage[TRANSPORT] = -1;
                basic_units_damage[INFANTRY] = 75;
                basic_units_damage[MECH] = 75;
                basic_units_damage[RECON] = 55;
                basic_units_damage[TANK] = 55;
                basic_units_damage[TANK_M] = 25;
                basic_units_damage[ANTI_AIR_TANK] = 25;
                basic_units_damage[ANTI_AIR_ML] = 65;
                basic_units_damage[ARTILLERY] = 65;
                basic_units_damage[ROCKET_L] = 65;
                basic_units_damage[FIGHTER] = 0;
                basic_units_damage[BOMBER] = 0;
                basic_units_damage[DESTROYER] = 25;
                basic_units_damage[HELICOPTER] = 65;
                basic_transports_damage[0] = 25;
                basic_transports_damage[1] = 60;
                basic_transports_damage[2] = 95;
                basic_transports_damage[3] = 55;
                break;
            default:
                break;
                
        }
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

    int Unit :: getRange_shoot() const
    {
        return this->range_shoot;
    }

    void Unit :: setRange_shoot(int range_shoot)
    {
        this->range_shoot = range_shoot;
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
    int Unit::getDamage_on_unit (TypeUnits type) const
    {
        return this->basic_units_damage[(int)type];
    }
    int Unit::getDamage_on_transport (TypeTransport type) const
    {
        return this->basic_transports_damage[(int)type];
    }

};
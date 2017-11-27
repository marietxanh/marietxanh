/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "../status/Building.h"
namespace status {

    Building::Building(TypeBuilding type_building, TEAM team)
    {
        this->setType_id(LAND);
        this->setType_land(BUILDING);
        this->type_building = type_building;
        this->health = 20;
        this->team = team;
        switch(type_building)
        {
            case TOWN:
                this->defense = 4;
                this->cost_mvmt = 1;
                break;
            case FACTORY:
                this->defense = 3;
                this->cost_mvmt = 1;
                break;
            case AIRPORT:
                this->defense = 3;
                this->cost_mvmt = 1;
                break;
            case HQ:
                this->defense = 4;
                this->cost_mvmt = 1;
                break;
            case PORT:
                this->defense = 3;
                this->cost_mvmt = 1;
                break;
            default:
                break;
        }
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

    void Building::setHealth(int health)
    {
        this->health += health;
    }

    TypeBuilding Building::getType_building() const
    {
        return this->type_building;
    }

    void Building::setTeam(TEAM team)
    {
        this->team = team;
    }
    
    TEAM Building::getTeam() const
    {
        return this->team;
    }
    
}




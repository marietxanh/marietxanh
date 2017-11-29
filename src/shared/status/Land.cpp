/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "../status/Land.h"
using namespace status;
using namespace std;

Land::Land()
{
    
}
Land::Land(TypeLand type_land)
{
    this->setType_id(LAND);
    this->setType_land(type_land);
    switch(type_land)
    {
        case PLAIN:
            this->defense = 1;
            this->cost_mvmt = 1;
            break;
        case FOREST:
            this->defense = 2;
            this->cost_mvmt = 2;
            break;
        default:
            break;
    }
}

bool Land::isBuilding() const
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

bool Land::isStatic() const
{
    return true;
}

void Land::affiche() const
{
    cout << "The land is a ";
    switch(this->getType_land())
    {
        case BUILDING: cout << "Building" << endl; break;
        case FOREST: cout << "Forest" << endl; break;
        case MOUNTAIN: cout << "Mountain" << endl; break;
        case PLAIN: cout << "Plain" << endl; break;
        case SHORE: cout << "Shore" << endl; break;
        case BEACH: cout << "Beach" << endl; break;
        case RIVER_MOUTH: cout << "River mouth" << endl; break;
        case SEA: cout << "Sea" << endl; break;
        case RIVER: cout << "River" << endl; break;
        case REEF: cout << "Reef" << endl; break;
        case CROSSROAD: cout << "Crossroad" << endl; break;
        case ROAD: cout << "Road" << endl; break;
        case BRIDGE: cout << "Bridge" << endl; break;
        default: break;
    }
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
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "../status/Transport.h"
using namespace status;

Transport::Transport(TypeTransport type_transport, TEAM team):Unit(TRANSPORT, team)
{
    this->type_transport = type_transport;
    if(type_transport == CRUISER)
    {
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
            basic_units_damage[BOMBER] = 65;
            basic_units_damage[DESTROYER] = 0;
            basic_units_damage[HELICOPTER] = 115;
            basic_transports_damage[LANDER] = 0;
            basic_transports_damage[APC] = 0;
            basic_transports_damage[CHOPPER] = 115;
            basic_transports_damage[CRUISER] = 0;
    }
    else
    {
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
            basic_units_damage[FIGHTER] = 0;
            basic_units_damage[BOMBER] = 0;
            basic_units_damage[DESTROYER] = 0;
            basic_units_damage[HELICOPTER] = 0;
            basic_transports_damage[LANDER] = 0;
            basic_transports_damage[APC] = 0;
            basic_transports_damage[CHOPPER] = 0;
            basic_transports_damage[CRUISER] = 0;
    }
}

Transport::~Transport()
{
    
}

int Transport::getOnBoard() const
{
    return onBoard;
}

int Transport::getMaximumCharge() const
{
    return maximumCharge;
}

void Transport::setMaximumCharge(int charge)
{
    this->maximumCharge = charge;
}

TypeTransport Transport::getType_transport() const
{
    return this->type_transport;
}

void Transport::setType_transport(TypeTransport type_transport)
{
    this->type_transport = type_transport;
}

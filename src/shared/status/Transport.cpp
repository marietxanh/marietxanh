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

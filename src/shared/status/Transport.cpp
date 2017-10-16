/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "../status/Transport.h"
using namespace status;

Transport::Transport(int abs, int ord, TypeTransport type_transport):Unit(abs, ord, TRANSPORT)
{
    this->type_transport = type_transport;
}

Transport::~Transport()
{
    
}

int const Transport::getOnBoard()
{
    return onBoard;
}

int const Transport::getMaximumCharge()
{
    return maximumCharge;
}

void Transport::setMaximumCharge(int charge)
{
    this->maximumCharge = charge;
}

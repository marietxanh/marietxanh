/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "../status/Transport.h"
using namespace status;

Transport::Transport(int abs, int ord, TypeTransport type_transport, TypeUnits type_units, TypeID type_id):Unit(abs, ord, type_units, type_id)
{
    this->type_transport = type_transport;
}

Transport::~Transport()
{
    
}

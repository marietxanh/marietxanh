/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "../status/Unit.h"
#include "../status/Transport.h"

Transport :: Transport ()
{

}

bool const Transport :: attackEnabled ()
{
    bool answer = false;
    if (this->getTypeTransport() == 1)
        answer = true;
    return answer;
}

bool const Transport :: isProvider ()
{
    bool answer = false;
    if (this->getTypeTransport() == 1)
        answer = true;
    return answer;
}

bool const Transport :: canLoad ()
{
    bool answer = false;
    if (this->onBoard != 1)
        answer = true;
    return answer;
}

bool const canUnload ()
{
    bool answer = false;
    if (this->onBoard == 1)
        answer = true;
    return answer;
}
   
bool const isTransport ()
{
    return true;
}


bool const canProvide ()
{
     bool answer = false;
    if (this->getTypeTransport() == 1)
        answer = true;
    return answer;
}

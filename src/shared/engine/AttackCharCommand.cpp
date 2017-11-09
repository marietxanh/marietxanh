/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Command.h"
#include "AttackCharCommand.h"

using namespace engine;
using namespace status;
using namespace std;

AttackCharCommand::AttackCommand()
{
    
}

AttackCharCommand::AttackCharCommand (Unit* shooter, Unit* receiver){
    receiver->setHealth(-(shooter->getAttack()));
    if(receiver->getHealth() <= 0) 
    {
        /*creer classe qui detruit le personnage*/
        std::cout << "Receiver is dead" << std::endl;
    }
    else
    {
        std::cout << "Receiver's health : " << receiver->getHealth() << std::endl;
    }
}

AttackCharCommand::~AttackCharCommand()
{
    
}

CommandTypeId AttackCharCommand::getTypeId () const{
    return ATTACK;
}
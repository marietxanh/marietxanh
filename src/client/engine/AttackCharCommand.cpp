/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Command.h"
#include "AttackCharCommand.h"

using namespace engine;
using namespace std;

AttackCharCommand::AttackCharCommand (int c){
    
}

CommandTypeId const AttackCharCommand::getTypeId (){
    return CommandTypeId(ATTACK);
}

void AttackCharCommand::execute (status::State& state){ /*Après avoir vérifié qu'un ennemi est à portée dans TestEngine*/
    if(/*vérifier que le personnage peut attaquer */){
        HandleAttackCommand attaque();
    } 
}
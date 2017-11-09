/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "MoveCharCommand.h"

MoveCharCommand::MoveCharCommand (int c){
    
}

CommandTypeId const MoveCharCommand::getTyepId (){
    return CommandTypeId(MOVE_CHAR);
}

void MoveCharCommand::execute (status::State& state){
    if(/*passage dans un environnement différent*/){
        WildCollisionCommand collision();
    }
    else {
        /*faire bouger le personnage*/
    }
    
}

// Setters and Getters
int MoveCharCommand::getCharacter() const{
    return this->character;
}

void MoveCharCommand::setCharacter(int character){
    this->character = /* ? */;
    
}

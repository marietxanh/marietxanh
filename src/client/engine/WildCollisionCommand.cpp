/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include"WildCollisionCommand.h"

WildCollisionCommand::WildCollisionCommand (int c, status::TypeLand l){
    
}

CommandTypeId const WildCollisionCommand::getTypeId (){
    return CommandTypeId(WILD_COLLISION);
}

void WildCollisionCommand::execute (status::State& state){
    /* si le personnage peut passer dans l'environnement faire les modifications nécessaires*/
    
}

// Setters and Getters
int WildCollisionCommand::getCharacter() const{
    return this->character;
}

void WildCollisionCommand::setCharacter(int c){
    this->character = c;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Command.h"
#include "HandleAttackCommand.h"

int HandleAttackCommand::attackTarget (status::State& state, int target, int character){
    
}

HandleAttackCommand::killTarget (status::State& state, int target){
    
}

HandleAttackCommand::killCharacter (status::State& state, int character){
    
}

CommandTypeId const HandleAttackCommand::getTypeId (){
    return CommandTypeId(HANDLE_ATK);
}

void HandleAttackCommand::execute (status::State& state){
    
}

    // Setters and Getters
int HandleAttackCommand::getCharacter() const{
    
}

void HandleAttackCommand::setCharacter(int character){
    
}

int HandleAttackCommand::getTarget() const{
    
}

void HandleAttackCommand::setTarget(int target){
    
}

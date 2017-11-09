/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <map>
#include <memory>
#include "Command.h"
#include "Engine.h"

using namespace engine;
using namespace status;

Engine::Engine (){
    
}
Engine::~Engine (){
    
}
const State& Engine::getState ()const{
    return this->currentState;
}

void Engine::addCommand (int priority, Command* cmd){
    currentCommands.insert(priority,cmd);  
}

void Engine::update (){
    for(const auto &pair : currentCommands){
        pair.second.execute();
    }
    currentState.day +=1;
    currentCommands.clear();   
}

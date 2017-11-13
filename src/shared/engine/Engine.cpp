/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <map>
#include <memory>
#include <iostream>
#include "../status.h"
#include "Engine.h"

using namespace engine;
using namespace status;

Engine::Engine ()
{
    this->state = new State();
}
Engine::~Engine ()
{
    delete state;
}

status::State* Engine::getState () const
{
    return this->state;
}
void Engine::setState (status::State* new_state)
{
    this->state = new_state;
}

void Engine::addPassiveCommands ()
{
    
}
void Engine::addCommand (Command* command)
{
    currentCommands.push_back(command);
}
void Engine::update ()
{
    for(auto command : currentCommands) command.execute();
}
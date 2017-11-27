/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "../status.h"
#include "Engine.h"

using namespace status;

namespace engine {

	Engine::Engine ()
	{
		state = new State();
	}
        
	Engine::~Engine ()
	{

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
		for(int i(0); i < ((int)(currentCommands.size())); i++)
		{
			currentCommands[i]->execute(this->state);
			delete currentCommands[i];
                        currentCommands[i] = 0;
		}
		currentCommands.clear();
	}
	
};

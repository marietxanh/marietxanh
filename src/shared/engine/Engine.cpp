/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <stack>
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
        
	const std::stack<Action*>& Engine::update ()
	{
            std::stack<Action*> pile;
		for(size_t i(0); i < currentCommands.size(); i++)
		{
			currentCommands[i]->execute(pile, this->state);
			//pile.push(currentCommands[i]);
                        currentCommands[i] = 0;
		}
		currentCommands.clear();
		return pile;
	}

 	void Engine::undo (std::stack<Action*>& actions)
        {
            for (size_t i(0); i < actions.size(); i++)
            {
                Action *new_action = actions.top(); actions.pop();
                new_action->undo(this->getState());
            }
        }
	
};

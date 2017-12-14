/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <fstream>
#include <stack>
#include "../status.h"
#include "Engine.h"

using namespace status;

namespace engine {

	Engine::Engine ()
	{
		state = new State();
                this->recording = false;
	}
        
	Engine::~Engine ()
	{
            if(enableRecord)
            {   
                std::ofstream file ("record.json",std::ofstream::out);
                file << recording;
                file.close();
            }
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
                        if(enableRecord) this->recording.append(currentCommands[i]);
                        else 
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
        
        bool Engine::getEnableRecord() const
        {
            return this->enableRecord;
        }
        void Engine::setEnableRecord(bool enableRecord)
        {
            this->enableRecord = enableRecord;
        }
        const Json::Value& Engine::getRecording() const
        {
            return this->recording;
        }
        void Engine::setRecording(const Json::Value& recording)
        {
            this->recording = recording;
        }
        bool Engine::getEnableReplay() const
        {
            return this->enableReplay;
        }
        void Engine::setEnableReplay(bool enableReplay)
        {
            this->enableReplay = enableReplay;
        }
	
};

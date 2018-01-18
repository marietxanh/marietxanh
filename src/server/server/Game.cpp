#include <iostream>
#include <time.h>
#include <fstream>
#include <unistd.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include <mutex>

#include "Game.hpp"
#include "./record.h"
#include "./../../shared/engine.h"
#include "./../../shared/status.h"
#include "./../../shared/ai.h"
#include "./../../client/render.h"

using namespace render;
using namespace engine;
using namespace status;
using namespace ai;

namespace server {
    
    Game::Game() {
    	
    	string file_name = "res/test_ai.txt";
		engine.addCommand(new LoadMap(file_name));
		engine.update();
	    int height = engine.getState()->getHeight();
    	int width = engine.getState()->getWidth();
		for(int i(0); i <  height; i++)
		{
		    for(int j(0); j < width; j++)
		    {
	            if(engine.getState()->getBuildings()->getElement(i, j) != NULL)
	            {
                    if(((Building*)(engine.getState()->getBuildings()->getElement(i, j)))->getType_building() == FACTORY)
                    {
                            engine.addCommand(new CreateUnit(INFANTRY, i, j));
                    }
	            }
            }
		}
		
		engine.update();
                setStatus(CREATING);

    }
    
    Game::~Game () {
        
    }

    Player& Game::player (int id) {
        return players[id];
    }
    
    engine::Engine& Game::getEngine () {
        return engine;
    }
    
    void Game::run () {
        
        
    }
    
    GameStatus Game::getStatus() const {
        return status;
    }
    
    void Game::setStatus(GameStatus status) {
        this-> status = status;
    }
    
    const std::vector<Player>& Game::getPlayers() const {
        return players;
    }
    
    void Game::setPlayers(const std::vector<Player>& players) {
        this->players = players;
    }

};


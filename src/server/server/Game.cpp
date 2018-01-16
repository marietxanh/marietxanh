#include <iostream>
#include <time.h>
#include <fstream>
#include <unistd.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include <mutex>

#include "Game.hpp"
#include "./../../client/render.h"

using namespace render;

namespace server {
    
    Game::Game() {

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
        
        string file_name = "res/test_ai.txt";
        engine.setEnableReplay(true);
        
        if (!engine.getEnableReplay())
        {
            engine.addCommand(new engine::LoadMap(file_name));
            engine.update();
        }
        engineThread(fonction_run, this, engine);

        Display display(engine.getState());
        std::mutex mtx;
        std::cout << "Window opens" << std::endl;
        while(display.getWindow().isOpen())
        {
            setStatus(RUNNING);
            mtx.lock();
            sf::Event event;

            while(display.checkEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {
                    display.closeWindow();
                    std::cout << "Window close request" << std::endl;
                }
            }

            //display.getUnits()->refresh_array();
            //display.refreshWindow();
            mtx.unlock();

            sleep(1);
        }

        //delete engine;
        engineThread->join();
        std::cout << "Window closed" << std::endl;
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


#include "Game.hpp"

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
        
    }
    
    GameStatus Game::getStatus() const {
        return status;
    }
    
    void Game::setStatus(GameStatus status) {
        this-> status = status;
    }

};


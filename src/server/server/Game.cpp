#include "Game.hpp"

namespace server {
    
    Game::Game() {

    }

    Player& Game::player (int id) {
        return players[id];
    }

};


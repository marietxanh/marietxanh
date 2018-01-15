#include "GameService.h"

namespace server {
    
    GameService::GameService (Game& game) {
        this->game = game;
    }
    
    GameStatus GameService::get (Json::Value& out, int id) const {
        if(game) return GameStatus::RUNNING;
        else return GameStatus::CREATING;
    }
};
    


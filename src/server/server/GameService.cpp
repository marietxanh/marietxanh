#include "GameService.h"

namespace server {
    
    GameService::GameService (Game& game) {
        this->game = game;
    }
    
    HttpStatus GameService::get (Json::Value& out, int id) const {
        if(game) return HttpStatus::CREATED;
        else return HttpStatus::NOT_IMPLEMENTED;
    }
};
    


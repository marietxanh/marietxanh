#include "GameService.h"

namespace server {
    
    GameService::GameService (Game& game) : AbstractService("/game"),
        game(game) {
    }
    
    HttpStatus GameService::get (Json::Value& out, int id) const {
        if(game.getStatus() == CREATING) return HttpStatus::OK;
        else return HttpStatus::OUT_OF_RESOURCES;
    }
};
    


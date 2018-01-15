#include "CommandsService.h"

namespace server {
    
    CommandsService::CommandsService (engine::Engine& engine) {
        this->engine = engine;
    }
    
    HttpStatus CommandsService::get (Json::Value& out, int id) const {
        
    }
    
    HttpStatus CommandsService::put (Json::Value& out, const Json::Value& in) {
        
    }

};
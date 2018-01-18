#include "CommandsService.h"
#include "engine/Engine.h"

namespace server {
    
    CommandsService::CommandsService (engine::Engine& engine) : AbstractService("/commands"),
        engine(engine) {
    }
    
    HttpStatus CommandsService::get (Json::Value& out, int id) const {
        // trouver la bonne condition, engine???
        if(engine.getEnableRecord()) {    
            //liste commandes sérialisées
            out["commands"] = engine.getRecording(); 
            return HttpStatus::OK;
        }
        else return HttpStatus::NOT_FOUND;
    }
    
    HttpStatus CommandsService::put (Json::Value& out, const Json::Value& in) {
        // sérialisation des commandes 
        Json::Value recording = engine.getRecording();
        recording.resize(recording.size() + 1);
        //currentCommands[i]->serialize(value);
        recording.append(in);
        
        /* //fonction qui renvoie le nombre de tour
        out["tour"] = engine. ; */
        
        return HttpStatus::CREATED;
    }

};
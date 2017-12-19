/** 
 * @file PlayerService.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "PlayerService.hpp"

namespace server {

    PlayerService::PlayerService (Game& game) : AbstractService("/player"),
        game(game) {

    }

    HttpStatus PlayerService::get (Json::Value& out, int id) const {
        const Player* player = game.getPlayer(id);
        if (!player)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
        out["name"] = player->name;
        out["teamcolor"] = player->teamcolor;
        return HttpStatus::OK;
    }

    HttpStatus PlayerService::post (const Json::Value& in, int id) {
        const Player* player = game.getPlayer(id);
        if (!player)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
        unique_ptr<Player> playermod (new Player(*player));
        if (in.isMember("name")) {
            playermod->name = in["name"].asString();
        }
        if (in.isMember("teamcolor")) {
            playermod->teamcolor = in["teamcolor"].asInt();
        }
        game.setPlayer(id,std::move(playermod));
        return HttpStatus::NO_CONTENT;
    }

    HttpStatus PlayerService::put (Json::Value& out,const Json::Value& in) {
        string name = in["name"].asString();
        int teamcolor = in["teamcolor"].asInt();
        out["id"] = game.addPlayer(make_unique<Player>(name,teamcolor));
        return HttpStatus::CREATED;
    }

    HttpStatus PlayerService::remove (int id) {
        const Player* player = game.getPlayer(id);
        if (!player)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
        game.removePlayer(id);
        return HttpStatus::NO_CONTENT;
    }
};
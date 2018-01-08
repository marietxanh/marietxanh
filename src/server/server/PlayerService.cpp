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
        const Player* player = &game.players[id];
        if (!player)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
        out["name"] = player->name;
        out["teamcolor"] = player->teamcolor;
        return HttpStatus::OK;
    }

    HttpStatus PlayerService::post (const Json::Value& in, int id) {
        const Player* player = &game.players[id];
        if (!player)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
        unique_ptr<Player> playermod (new Player(*player));
        if (in.isMember("name")) {
            playermod->name = in["name"].asString();
        }
        if (in.isMember("teamcolor")) {
            playermod->teamcolor = (status::TEAM)(in["teamcolor"].asInt()); 
        }
        game.players.push_back(*playermod);
        return HttpStatus::NO_CONTENT;
    }

    HttpStatus PlayerService::put (Json::Value& out,const Json::Value& in) {
        string name = in["name"].asString();
        status::TEAM teamcolor = (status::TEAM)(in["teamcolor"].asInt());
        game.players.push_back(Player(name,teamcolor));
        out["id"] = game.players.size();
        return HttpStatus::CREATED;
    }

    HttpStatus PlayerService::remove (int id) {
        const Player* player = &game.players[id];;
        if (!player)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
        game.players.erase(game.players.begin()+id);
        return HttpStatus::NO_CONTENT;
    }
};
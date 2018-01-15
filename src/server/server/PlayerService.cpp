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
         if (game.players.size() > id && id >= 0)
    {
        const Player* player = &game.players[id];
        out["name"] = player->name;
        out["teamcolor"] = player->teamcolor;
        return HttpStatus::OK;
    }
    else if (id < 0)
    {
        out["number_players"] = game.players.size();
        return HttpStatus::OK;
    }
    else
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
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

    HttpStatus PlayerService::put (Json::Value& out, const Json::Value& in) {
        if (game.players.size()< 2) {
            std::string name = in["name"].asString();
            status::TEAM teamcolor = (status::TEAM)(in["teamcolor"].asInt());
            game.players.push_back(Player(name, teamcolor, true));
            out["id"] = game.players.size() - 1;
            return HttpStatus::CREATED;
        }
        else return HttpStatus::OUT_OF_RESOURCES;
    }

    HttpStatus PlayerService::remove (int id) {
        const Player* player = &game.players[id];;
        if (!player)
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
        game.players.erase(game.players.begin()+id);
        return HttpStatus::NO_CONTENT;
    }
};
#include "Player.hpp"

namespace server {
  
    Player::Player (std::string name, status::TEAM teamcolor, bool free_player) : name(name),teamcolor(teamcolor),  free_player(free_player){
        
    }
    
};
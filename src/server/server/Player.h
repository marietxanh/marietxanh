// Generated by dia2code
#ifndef SERVER__PLAYER__H
#define SERVER__PLAYER__H

#include <string>

#include "status/TEAM.h"

namespace server {

  /// class Player - 
  class Player {
    // Attributes
  public:
    std::string name;
    status::TEAM teamcolor;
    bool free_player     = true;
    // Operations
  public:
    Player (std::string name, status::TEAM teamcolor, bool free_player);
    // Setters and Getters
  };

};

#endif

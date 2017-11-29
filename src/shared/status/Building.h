// Generated by dia2code
#ifndef STATUS__BUILDING__H
#define STATUS__BUILDING__H


namespace status {
  class Land;
}

#include "TEAM.h"
#include "TypeBuilding.h"
#include "Land.h"

namespace status {

  /// class Building - 
  class Building : public status::Land {
    // Associations
    // Attributes
  public:
    TEAM team;
  private:
    int tax_inc     = 1000;
    int const healer     = 2;
    int health;
    TypeBuilding type_building;
    // Operations
  public:
    Building ();
    Building (TypeBuilding type_building, TEAM team);
    ~Building ();
    bool canCraft () const;
    int getHealth () const;
    TypeBuilding getType_building () const;
    void setHealth (int health);
    void setTeam (TEAM team);
    TEAM getTeam () const;
    // Setters and Getters
  };

};

#endif

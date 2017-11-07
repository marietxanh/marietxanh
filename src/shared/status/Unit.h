// Generated by dia2code
#ifndef STATUS__UNIT__H
#define STATUS__UNIT__H


namespace status {
  class Element;
}

#include "TypeUnits.h"
#include "Element.h"

namespace status {

  /// class Unit - 
  class Unit : public status::Element {
    // Associations
    // Attributes
  protected:
    int amplitude_mvmt;
    int range_mvmt;
    int fuel_tank;
    int fuel_consumption;
    int rocket;
    int attack;
    int health;
    TypeUnits type_unit;
    int team;
    // Operations
  public:
    Unit (TypeUnits type_units);
    TypeUnits getTypeUnit () const;
    void setTypeUnit (TypeUnits type);
    bool isStatic () const;
    bool isTransport () const;
    void affiche () const;
    // Setters and Getters
    int getAmplitude_mvmt() const;
    void setAmplitude_mvmt(int amplitude_mvmt);
    int getRange_mvmt() const;
    void setRange_mvmt(int range_mvmt);
    int getFuel_tank() const;
    void setFuel_tank(int fuel_tank);
    int getFuel_consumption() const;
    void setFuel_consumption(int fuel_consumption);
    int getRocket() const;
    void setRocket(int rocket);
    int getAttack() const;
    void setAttack(int attack);
    int getHealth() const;
    void setHealth(int health);
    TypeUnits getType_unit() const;
    void setType_unit(TypeUnits type_unit);
    int getTeam() const;
    void setTeam(int team);
  };

};

#endif

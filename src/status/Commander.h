// Generated by dia2code
#ifndef STATUS__COMMANDER__H
#define STATUS__COMMANDER__H


namespace status {
  class Building;
  class Unit;
}

#include "TypeCommander.h"
#include "Building.h"
#include "Unit.h"

namespace status {

  /// class Commander - 
  class Commander {
    // Associations
    // Attributes
  private:
    int bonusMvmt;
    int bonusHealth;
    int bonusAtk;
    int bonusRange;
    bool bonusRound;
    int power_meter;
    TypeCommander type_commander;
    // Operations
  public:
    Commander (int bonusMvmt = 0, int bonusRange = 0, int bonusAtk = 0);
    ~Commander ();
    // Setters and Getters
  };

};

#endif

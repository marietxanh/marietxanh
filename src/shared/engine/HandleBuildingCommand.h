// Generated by dia2code
#ifndef ENGINE__HANDLEBUILDINGCOMMAND__H
#define ENGINE__HANDLEBUILDINGCOMMAND__H


namespace status {
  class State;
};
namespace engine {
  class Command;
}

#include "status/TypeCommander.h"
#include "Command.h"

namespace engine {

  /// class HandleBuildingCommand - 
  class HandleBuildingCommand : public engine::Command {
    // Attributes
  private:
    int building;
    // Operations
  public:
    int getMoney (status::TypeCommander owner);
    CommandTypeId const getTypeId ();
    void execute (status::State& state);
    // Setters and Getters
  };

};

#endif
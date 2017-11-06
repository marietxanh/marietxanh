// Generated by dia2code
#ifndef ENGINE__COMMAND__H
#define ENGINE__COMMAND__H


namespace status {
  class State;
}

#include "CommandTypeId.h"
#include "status/State.h"

namespace engine {

  /// class Command - 
  class Command {
    // Operations
  public:
    virtual ~Command ();
    virtual CommandTypeId const getTypeId () = 0;
    virtual void execute (state::State& state) = 0;
    // Setters and Getters
  };

};

#endif

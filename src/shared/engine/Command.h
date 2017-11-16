// Generated by dia2code
#ifndef ENGINE__COMMAND__H
#define ENGINE__COMMAND__H

#include "status.h"

namespace status {
  class State;
}

#include "CommandTypeID.h"

namespace engine {

  /// class Command - 
  class Command {
    // Operations
  public:
    virtual ~Command ();
    virtual CommandTypeID getTypeID () const = 0;
    virtual void execute (status::State* state) = 0;
    // Setters and Getters
  };

};

#endif

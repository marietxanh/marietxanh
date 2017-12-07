// Generated by dia2code
#ifndef ENGINE__RESETUNITS__H
#define ENGINE__RESETUNITS__H

#include <stack>
#include <memory>
#include "status.h"

namespace engine {
  class Action;
};
namespace status {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeID.h"
#include "Action.h"
#include "Command.h"

namespace engine {

  /// class ResetUnits - 
  class ResetUnits : public engine::Command {
    // Operations
  public:
    ResetUnits ();
    CommandTypeID getTypeID () const;
    void execute (std::stack<std::shared_ptr<Action> >& actions, status::State* state);
    // Setters and Getters
  };

};

#endif

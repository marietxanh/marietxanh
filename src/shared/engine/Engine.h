// Generated by dia2code
#ifndef ENGINE__ENGINE__H
#define ENGINE__ENGINE__H

#include "status.h"
#include <vector>

namespace status {
  class State;
};
namespace engine {
  class Command;
}

#include "status/State.h"
#include "Command.h"

namespace engine {

  /// class Engine - 
  class Engine {
    // Associations
    // Attributes
  private:
    status::State* state;
    std::vector<Command*> currentCommands;
    // Operations
  public:
    Engine ();
    ~Engine ();
    status::State* getState () const;
    void setState (status::State* new_state);
    void addPassiveCommands ();
    void addCommand (Command* command);
    void update ();
    // Setters and Getters
  };

};

#endif

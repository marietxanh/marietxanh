// Generated by dia2code
#ifndef ENGINE__LOADMAP__H
#define ENGINE__LOADMAP__H

#include <string>
#include "status.h"

namespace status {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeID.h"
#include "Command.h"

namespace engine {

  /// class LoadMap - 
  class LoadMap : public engine::Command {
    // Attributes
  private:
    std::string file_name;
    // Operations
  public:
    LoadMap (const std::string& file_name);
    ~LoadMap ();
    CommandTypeID getTypeID () const;
    void execute (status::State* state);
    // Setters and Getters
  };

};

#endif

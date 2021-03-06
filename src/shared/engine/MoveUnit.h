// Generated by dia2code
#ifndef ENGINE__MOVEUNIT__H
#define ENGINE__MOVEUNIT__H

#include <stack>
#include "status.h"
#include <json/json.h>

namespace engine {
  class Action;
};
namespace status {
  class State;
};
namespace engine {
  class MoveUnit;
  class Command;
}

#include "CommandTypeID.h"
#include "Command.h"

namespace engine {

  /// class MoveUnit - 
  class MoveUnit : public engine::Command {
    // Attributes
  protected:
    int height_start;
    int width_start;
    int height_end;
    int width_end;
    // Operations
  public:
    MoveUnit (int height_start, int width_start, int height_end, int width_end);
    CommandTypeID getTypeID () const;
    void execute (std::stack<Action*>& actions, status::State* state);
    ~MoveUnit ();
    void serialize (Json::Value& out) const;
    MoveUnit* deserialize (const Json::Value& in);
    // Setters and Getters
    int getHeight_start() const;
    void setHeight_start(int height_start);
    int getWidth_start() const;
    void setWidth_start(int width_start);
    int getHeight_end() const;
    void setHeight_end(int height_end);
    int getWidth_end() const;
    void setWidth_end(int width_end);
  };

};

#endif

// Generated by dia2code
#ifndef ENGINE__ATTACKUNIT__H
#define ENGINE__ATTACKUNIT__H

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
  class AttackUnit;
  class Command;
}

#include "CommandTypeID.h"
#include "Command.h"

namespace engine {

  /// class AttackUnit - 
  class AttackUnit : public engine::Command {
    // Attributes
  protected:
    int height_shooter;
    int width_shooter;
    int height_target;
    int width_target;
    // Operations
  public:
    AttackUnit (int height_shooter, int width_shooter, int height_target, int width_target);
    ~AttackUnit ();
    CommandTypeID getTypeID () const;
    void execute (std::stack<Action*>& actions, status::State* state);
    void serialize (Json::Value& out) const;
    AttackUnit* deserialize (const Json::Value& in);
    // Setters and Getters
    int getHeight_shooter() const;
    void setHeight_shooter(int height_shooter);
    int getWidth_shooter() const;
    void setWidth_shooter(int width_shooter);
    int getHeight_target() const;
    void setHeight_target(int height_target);
    int getWidth_target() const;
    void setWidth_target(int width_target);
  };

};

#endif

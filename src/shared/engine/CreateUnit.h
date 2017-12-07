// Generated by dia2code
#ifndef ENGINE__CREATEUNIT__H
#define ENGINE__CREATEUNIT__H

#include "status.h"
#include <stack>

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
#include "Command.h"

namespace engine {

  /// class CreateUnit - 
  class CreateUnit : public engine::Command {
    // Attributes
  protected:
    status::TypeUnits type_unit;
    int height;
    int width;
    // Operations
  public:
    CreateUnit (status::TypeUnits type_unit, int height, int width);
    ~CreateUnit ();
    CommandTypeID getTypeID () const;
    void execute (std::stack<Action*>& actions, status::State* state);
    // Setters and Getters
    const status::TypeUnits& getType_unit() const;
    void setType_unit(const status::TypeUnits& type_unit);
    int getHeight() const;
    void setHeight(int height);
    int getWidth() const;
    void setWidth(int width);
  };

};

#endif

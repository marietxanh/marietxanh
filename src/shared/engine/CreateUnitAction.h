// Generated by dia2code
#ifndef ENGINE__CREATEUNITACTION__H
#define ENGINE__CREATEUNITACTION__H

#include "status.h"

namespace status {
  class Element;
  class State;
};
namespace engine {
  class Action;
}

#include "Action.h"
#include "status/Element.h"

namespace engine {

  /// class CreateUnitAction - 
  class CreateUnitAction : public engine::Action {
    // Attributes
  private:
    status::Element* prev_unit;
  protected:
    status::TypeUnits type_unit;
    int height;
    int width;
    // Operations
  public:
    CreateUnitAction (status::TypeUnits type_unit, int height, int width);
    void apply (status::State* state);
    void undo (status::State* state);
    void setElement (status::Element* element);
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

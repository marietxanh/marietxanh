// Generated by dia2code
#ifndef RENDER__DISPLAY__H
#define RENDER__DISPLAY__H

#include <SFML/Graphics.hpp>
#include "status.h"

namespace sf {
  class RenderWindow;
};
namespace status {
  class State;
};
namespace render {
  class ElementTabLayer;
}

#include "status/State.h"
#include "ElementTabLayer.h"

namespace render {

  /// class Display - 
  class Display {
    // Associations
    // Attributes
  private:
    sf::RenderWindow window;
    status::State* state;
    ElementTabLayer* lands;
    ElementTabLayer* buildings;
    ElementTabLayer* units;
    // Operations
  public:
    Display (status::State* state);
    ~Display ();
    void refreshWindow ();
    const sf::RenderWindow& getWindow () const;
    checkEvent (const sf::Event& event);
    void closeWindow ();
    // Setters and Getters
  };

};

#endif

// Generated by dia2code
#ifndef STATUS__STATE__H
#define STATUS__STATE__H

<<<<<<< HEAD
#include <string>
=======
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
#include <stdlib.h>

namespace status {
  class ElementTab;
}

#include "ElementTab.h"

namespace status {

  /// class State - 
  class State {
    // Associations
    // Attributes
  private:
<<<<<<< HEAD
    ElementTab* lands;
    ElementTab* buildings;
    ElementTab* units;
    std::string text_file_name;
=======
    ElementTab* grid;
    ElementTab* units;
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
    size_t day;
    size_t timer     = 90;
    int width;
    int height;
    int tile_width;
    int tile_height;
    // Operations
  public:
    State (std::string& text_file_name);
    ~State ();
<<<<<<< HEAD
    ElementTab* getLands () const;
    ElementTab* getBuildings () const;
    ElementTab* getUnits () const;
    void setDimensions (std::string& text_file_name);
=======
    ElementTab* getGrid ();
    ElementTab* getCharacters ();
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
    // Setters and Getters
  };

};

#endif

// Generated by dia2code
#ifndef STATUS__ELEMENTTAB__H
#define STATUS__ELEMENTTAB__H

#include <vector>
<<<<<<< HEAD
#include <string>
=======
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42

namespace status {
  class Element;
}

#include "Element.h"

namespace status {

  /// class ElementTab - 
  class ElementTab {
    // Associations
    // Attributes
  private:
<<<<<<< HEAD
    std::vector<std::vector<Element*>> element_array;
    std::vector<std::vector<int> > layer_array;
    std::vector<std::string> textures_references;
=======
    int width;
    int height;
    std::vector<std::vector<Element*>> array;
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
    // Operations
  public:
    ElementTab (std::string& text_file_name, int width, int height, std::string& type_element);
    ~ElementTab ();
<<<<<<< HEAD
    Element* getElement (int i, int j);
    void setElement (int i, int j, Element* element);
    void setLayer_array (std::string& text_file_name, std::string& type_layer);
    void setElement_array (std::string& type_layer);
    void setTextures_references (std::string& text_file_name, std::string& type_layer);
=======
    int getWidth () const;
    int getHeight () const;
    Element* getElement (int i, int j);
    void setElement (int i, int j, Element* element);
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
    // Setters and Getters
  };

};

#endif

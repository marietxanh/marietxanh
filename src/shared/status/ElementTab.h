// Generated by dia2code
#ifndef STATUS__ELEMENTTAB__H
#define STATUS__ELEMENTTAB__H

#include <vector>
#include <string>

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
    std::vector<std::vector<Element*> > element_array;
    std::vector<std::vector<int> > layer_array;
    std::vector<std::string> textures_references;
    // Operations
  public:
    ElementTab (std::string& text_file_name, int width, int height, std::string& type_element);
    ~ElementTab ();
    Element* getElement (int i, int j);
    void setElement (int i, int j, Element* element);
    void setLayer_array (std::string& text_file_name, std::string& type_layer);
    void setElement_array (std::string& type_layer);
    void setTextures_references (std::string& text_file_name, std::string& type_layer);
    // Setters and Getters
  };

};

#endif

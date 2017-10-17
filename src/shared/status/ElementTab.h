// Generated by dia2code
#ifndef STATUS__ELEMENTTAB__H
#define STATUS__ELEMENTTAB__H

#include <vector>
#include <memory>

namespace status {
  class Element;
}

#include "TypeID.h"
#include "Element.h"

namespace status {

  /// class ElementTab - 
  class ElementTab {
    // Associations
    // Attributes
  private:
    int width;
    int height;
    std::vector<std::vector<std::unique_ptr<Element>>> array;
    // Operations
  public:
    ElementTab (int width, int height, TypeID type_id);
    ~ElementTab ();
    int getWidth () const;
    int getHeight () const;
    std::unique_ptr<Element>& getElement (int i, int j);
    void setElement (int i, int j, std::unique_ptr<Element>& element);
    // Setters and Getters
  };

};

#endif

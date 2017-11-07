// Generated by dia2code
#ifndef RENDER__ELEMENTTABLAYER__H
#define RENDER__ELEMENTTABLAYER__H


namespace status {
  class ElementTab;
};
namespace render {
  class Layer;
}

#include "Layer.h"
#include "status/ElementTab.h"

namespace render {

  /// class ElementTabLayer - 
  class ElementTabLayer : public render::Layer {
    // Attributes
  private:
    status::ElementTab* element_tab;
    // Operations
  public:
    ElementTabLayer (char* text_file_name, char* type_layer);
    status::ElementTab* getElement_tab () const;
    // Setters and Getters
  };

};

#endif

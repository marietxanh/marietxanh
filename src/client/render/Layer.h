// Generated by dia2code
#ifndef RENDER__LAYER__H
#define RENDER__LAYER__H


namespace render {
  class Surface;
  class TileSet;
}

#include "TileSet.h"
#include "Surface.h"

namespace render {

  /// class Layer - 
  class Layer {
    // Associations
    // Attributes
  private:
    Surface* surface;
    TileSet* tileset;
    // Operations
  public:
    Layer ();
    virtual ~Layer ();
    Surface* getSurface () const;
    void setSurface (Surface* surface);
    virtual void initSurface () = 0;
    // Setters and Getters
  };

};

#endif

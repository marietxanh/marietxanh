// Generated by dia2code
#ifndef RENDER__CHARSTILESET__H
#define RENDER__CHARSTILESET__H

#include <vector>
#include <string>

namespace render {
  class Tile;
};
namespace status {
  class Element;
};
namespace render {
  class TileSet;
}

#include "TileSet.h"

namespace render {

  /// class CharsTileSet - 
  class CharsTileSet : public render::TileSet {
    // Attributes
  private:
    std::vector<std::vector<Tile*>> units;
    std::vector<std::vector<Tile*>> transports;
    // Operations
  public:
    CharsTileSet ();
    ~CharsTileSet ();
    int getCellWidth () const;
    int getCellHeight () const;
    std::string getImageFile () const;
    Tile* getTile (status::Element* element);
    // Setters and Getters
  };

};

#endif
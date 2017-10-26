// Generated by dia2code
#ifndef RENDER__TILE__H
#define RENDER__TILE__H

#include <string>

namespace render {

  /// class Tile - 
  class Tile {
    // Attributes
  private:
    std::string adress_file;
    int height;
    int width;
    // Operations
  public:
    Tile ();
    Tile (std::string& adress_file, int height, int width);
    ~Tile ();
    int getWidth () const;
    int getHeight () const;
    std::string& getAdressFile () const;
    // Setters and Getters
  };

};

#endif

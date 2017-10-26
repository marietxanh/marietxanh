// Generated by dia2code
#ifndef RENDER__SURFACE__H
#define RENDER__SURFACE__H

#include <vector>
#include <SFML/Graphics.hpp>
#include <string>

namespace sf {
  class Texture;
  class VertexArray;
  class Drawable;
  class Transformable;
}


namespace render {

  /// class Surface - 
  class Surface : public sf::Drawable, public sf::Transformable {
    // Attributes
  private:
    std::vector<sf::Texture> textures;
    sf::VertexArray quads;
    // Operations
  public:
    Surface ();
    ~Surface ();
    void loadTexture (std::string& texture_file_name);
    void initQuads (int width, int height);
    void setQuadPosition (sf::Vertex* quad, int abscissa, int ordinate, int tile_width, int tile_height, int height, int width);
    void setQuadTextureCoordinates (sf::Vertex* quad, int tile_witdh, int tile_height, sf::Texture texture);
    void draw (sf::RenderTarget& target, sf::RenderStates states);
    sf::VertexArray& getQuad (int i, int j);
    // Setters and Getters
  };

};

#endif
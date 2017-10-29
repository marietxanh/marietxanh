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
    std::vector<sf::VertexArray> quads;
    std::vector<std::vector<int> > layer_array;
    // Operations
  public:
    Surface ();
    ~Surface ();
    void loadTexture (std::string& texture_file_name);
    void initQuads (int width, int height);
    void setQuadPosition (sf::Vertex* quad, int abscissa, int ordinate, int tile_width, int tile_height, int texture_width, int texture_height);
    void setQuadTextureCoordinates (sf::Vertex* quad, int texture_witdh, int texture_height);
    void draw (sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Vertex* getQuad (int i, int j);
    sf::Texture* getTexture (int i);
    int getLayerArray (int i, int j) const;
    void setLayerArray (int height, int width);
    void addValue (int value, int i, int j);
    // Setters and Getters
  };

};

#endif

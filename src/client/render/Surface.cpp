/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <fstream>
#include "Surface.h"
using namespace render;
using namespace sf;
using namespace std;

Surface::Surface ()
{
    
}
Surface::~Surface ()
{

}
void Surface::loadTexture (string& file_name)
{
    string image_file = "res/" + file_name + ".png";
    Texture nouvelle_texture;
    textures.push_back(nouvelle_texture);
    int end = int(textures.size()) - 1;
    if(!textures[end].loadFromFile(image_file)) cout << "Cannot load file" << endl;
    else cout << image_file << " loaded with success !" << endl;
}
void Surface::initQuads (int width, int height)
{
    quads.resize(width * height);
    for(int i(0); i < (width * height); i++)
    {
        quads[i].setPrimitiveType(sf::Quads);
        quads[i].resize(4);
    }
}
void Surface::setQuadPosition (Vertex* quad, int abscissa, int ordinate, int tile_width, int tile_height, int texture_width, int texture_height)
{
    sf::Vector2u tileset(tile_width, tile_height);
    sf::Vector2u textureset(texture_width, texture_height);
    if(ordinate > 0)
    {
        quad[0].position = sf::Vector2f(abscissa * tileset.x, ordinate * tileset.y - (textureset.y - tileset.y));
        quad[1].position = sf::Vector2f((abscissa + 1) * tileset.x, ordinate * tileset.y - (textureset.y - tileset.y));
    }
    else
    {
        quad[0].position = sf::Vector2f(abscissa * tileset.x, tileset.y);
        quad[1].position = sf::Vector2f((abscissa + 1) * tileset.x, tileset.y);
    }
    quad[2].position = sf::Vector2f((abscissa + 1 ) * tileset.x, (ordinate + 1) * tileset.y);
    quad[3].position = sf::Vector2f(abscissa * tileset.x, (ordinate + 1) * tileset.y);
}
void Surface::setQuadTextureCoordinates (Vertex* quad, int texture_width, int texture_height)
{
    quad[0].texCoords = sf::Vector2f(0, 0);
    quad[1].texCoords = sf::Vector2f(texture_width, 0);
    quad[2].texCoords = sf::Vector2f(texture_width, texture_height);
    quad[3].texCoords = sf::Vector2f(0, texture_height);
}

void Surface::draw (RenderTarget& target, RenderStates states) const
{
    // on applique la transformation
    states.transform *= getTransform();

    // et on dessine enfin le tableau de vertex
    states.texture = &textures[0];  

    target.draw(quads[0], states);

}
//*
Vertex* Surface::getQuad(int i, int j)
{
    return &(this->quads[i][0]);
}
//*/

Texture* Surface::getTexture(int i)
{
    return &textures[i];   
}

void Surface::setLayerArray(int height, int width)
{
    layer_array.resize(height);
    for(int i(0); i < height; i++)
    {
        layer_array[i].resize(width);
    }
}

int Surface::getLayerArray(int i, int j) const
{
    return layer_array[i][j]; 
}
void Surface::addValue(int value, int i, int j)
{
    this->layer_array[i][j] = value;
}
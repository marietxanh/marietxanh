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
    string image_file = "../res/" + file_name + ".png";
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
    quad[0].position = sf::Vector2f(abscissa * tile_width - (texture_width - tile_width) / 2, ordinate * tile_height - (texture_height - tile_height));
    quad[1].position = sf::Vector2f((abscissa + 1 ) * tile_width + (texture_width - tile_width) / 2, ordinate * tile_height - (texture_height - tile_height));
    quad[2].position = sf::Vector2f((abscissa + 1 ) * tile_width + (texture_width - tile_width) / 2, (ordinate + 1) * tile_height);
    quad[3].position = sf::Vector2f(abscissa * tile_width - (texture_width - tile_width) / 2, (ordinate + 1) * tile_height);
    cout << "Quad loaded" << endl;
}
void Surface::setQuadTextureCoordinates (Vertex* quad, int texture_width, int texture_height)
{
    quad[0].texCoords = sf::Vector2f(0, 0);
    quad[1].texCoords = sf::Vector2f(texture_width, 0);
    quad[2].texCoords = sf::Vector2f(texture_width, texture_height);
    quad[3].texCoords = sf::Vector2f(0, texture_height);
    cout << "Quad loaded" << endl;
}

void Surface::draw (RenderTarget& target, RenderStates states) const
{
    // on applique la transformation
    states.transform *= getTransform();

    // on applique la texture du tileset
    //states.texture = textures;

    // et on dessine enfin le tableau de vertex
    for(int i(0); i < int(layer_array.size()); i++)
    {
        for(int j(0); j < int(layer_array[i].size()); j++)
        {
            states.texture = &textures[layer_array[i][j] - 1];  
        }
        target.draw(quads[i], states);
    }

}

sf::Vertex* Surface::getQuad(int i, int j)
{
    return &quads[i][j];
}

sf::Texture* Surface::getTexture(int i)
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
    layer_array[i][j] = value;
}
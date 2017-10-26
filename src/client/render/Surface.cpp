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
    texture.loadFromFile(image_file);
    /*inserer un CHECK pour verifier l'ouverture de l'image*/
}
void Surface::initQuads (int width, int height)
{
    quads.setPrimitiveType(sf::Quads);
    quads.resize(width * height * 4);    
}
void Surface::setQuadsCorners (Vertex* quad, int i, int j, int tilewidth, int tileheight)
{
    quad[0].position = sf::Vector2f(i * tilewidth, j * tileheight);
    quad[1].position = sf::Vector2f((i + 1) * tilewidth, j * tileheight);
    quad[2].position = sf::Vector2f((i + 1) * tilewidth, (j + 1) * tileheight);
    quad[3].position = sf::Vector2f(i * tilewidth, (j + 1) * tileheight);    
}
void Surface::setQuadsCoordinate (Vertex* quad, int i, int j, int tilewidth, int tileheight)
{
    quad[0].texCoords = sf::Vector2f(i * tilewidth, j * tileheight);
    quad[1].texCoords = sf::Vector2f((i + 1) * tilewidth, j * tileheight);
    quad[2].texCoords = sf::Vector2f((i + 1) * tilewidth, (j + 1) * tileheight);
    quad[3].texCoords = sf::Vector2f(i * tilewidth, (j + 1) * tileheight); 
}
void Surface::draw (RenderTarget& target, RenderStates states)
{
    // on applique la transformation
    states.transform *= getTransform();

    // on applique la texture du tileset
    states.texture = &texture;

    // et on dessine enfin le tableau de vertex
    target.draw(quads, states);    
}
void Surface::seekForData(string& file_name)
{
    
}
#include "Layer.h"
#include <fstream>
#include <iostream>

using namespace std;
using namespace render;
using namespace sf;

Layer::Layer()
{
    pack_textures = new TexturesPack();
}

Layer::~Layer()
{
    
}

sf::Sprite Layer::getSprite(int i, int j) const
{
    return sprites[i][j];
}

TexturesPack* Layer::getTextures_pack() const
{
    return pack_textures;
}

int Layer::getHeight()const
{
    return height;
}

void Layer::setHeight(int height)
{
    this->height = height;
}

int Layer::getWidth() const
{
    return width;
}

void Layer::setWidth(int width)
{
    this->width = width;
}

std::vector<std::vector<sf::Sprite> > Layer::getSpritesTab () const
{
    return this->sprites;
}

void Layer::setSpritesTabDim ()
{
    this->sprites.resize(height);
    for(int i(0); i < height; i++)
    {
        this->sprites[i].resize(width);
    }
    std::cout << "SpritesTab OK" << std::endl;
}
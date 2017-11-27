#include "TexturesPack.h"
#include <iostream>
#include <SFML/OpenGL.hpp>

using namespace render;
using namespace std;
using namespace sf;

TexturesPack::TexturesPack()
{

}

const Texture& TexturesPack::getText(int i)
{
	return textures[i];
}

const vector<Texture>& TexturesPack::getTexturesArray() const
{
	return textures;
}

void TexturesPack::setTexturesArray (const std::vector<std::string>& references_array)
{
    int size = references_array.size();
    this->textures.resize(size);    
    for(int i(0); i < size; i++)
    {
        if(references_array[i].size() > 0){
            if(!this->textures[i].loadFromFile(references_array[i]))
            {
                std::cout << "loadFromFile failed" << std::endl;
            }
        }
    }
}

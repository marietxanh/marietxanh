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

void TexturesPack::loadTextures(const string& image_file_name, int i)
{
    if(textures.size() == 0)
    {
        cout << "RESIZE" << endl;
        textures.resize(i);
        textures[i - 1].loadFromFile(image_file_name);
    }
    
    else
    {
        Texture texture;
        if(!texture.loadFromFile(image_file_name)) cout << "Cannot load " << image_file_name;
        textures.push_back(texture);
    }
}

void TexturesPack::setTexturesArray (const std::vector<std::string>& references_array)
{
    int size = references_array.size();
    this->textures.resize(size);    
    for(int i(0); i < size; i++)
    {
        if(references_array[i].size() > 0){
            std::cout << i << " : " << references_array[i] << std::endl;
            if(!this->textures[i].loadFromFile(references_array[i]))
            {
                std::cout << "loadFromFile failed" << std::endl;
            }
        }
    }
    std::cout << "setTexturesArray OK" << std::endl;
}

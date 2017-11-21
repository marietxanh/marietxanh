#include "TexturesPack.h"
#include <iostream>
#include <SFML/OpenGL.hpp>

using namespace render;
using namespace std;
using namespace sf;

TexturesPack::TexturesPack()
{

}

Texture TexturesPack::getText(int i)
{
	return textures[i];
}

vector<Texture> TexturesPack::getTexturesArray() const
{
	return textures;
}

void TexturesPack::loadTextures(string& image_file_name, int i)
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

void TexturesPack::setTexturesArray (std::vector<std::string> references_array)
{
    int size = references_array.size();
    this->textures.resize(size);    
    for(int i(0); i < size; i++)
    {
        if(references_array[i].size() > 0){
            this->textures[i].loadFromFile(references_array[i]);
        }
    }
    std::cout << "setTexturesArray OK" << std::endl;
}

#include "Layer.h"
#include <fstream>
#include <iostream>

using namespace std;
using namespace render;
using namespace sf;

Layer::Layer(char* text_file_name, char* type_layer)
{
	this->text_file_name = text_file_name;
	this->type_layer = type_layer;
        setSpritesPositions();
        cout << "Layer loaded" << endl;
}

void Layer::setSpritesPositions()
{
    /*A REFAIRE PUISQUE TOUT EST CHARGE DANS LE PACKAGE STATUS*/
    int width = 0, height = 0;
    sprites.resize(getHeight());
    for(int i(0); i < getHeight(); i++)
    {
        sprites[i].resize(this->getWidth());
            for(int j(0); j < getWidth(); j++)
            {
                if((int)(layer_array[i][j]) > 0){
                    width = (int)(pack_textures.getText(layer_array[i][j]).getSize().x);
                    height = (int)(pack_textures.getText(layer_array[i][j]).getSize().y);
                    cout << width << '\t' << height << '\t';
                    sprites[i][j].setPosition(sf::Vector2f(width * j, height * i));
                    sprites[i][j].setTexture(pack_textures.getText(layer_array[i][j] - 1));
                }
                else
                {
                    cout << "-1\t-1\t";
                    sprites[i][j].setPosition(sf::Vector2f(16 * j, 16 * i));
                }
            }
        cout << endl;

    }
}

sf::Sprite Layer::getSprite(int i, int j) const
{
    return sprites[i][j];
}

TexturesPack Layer::getTextures_pack() const
{
    return pack_textures;
}

int Layer::getHeight()const
{
    return height;
}

int Layer::getWidth() const
{
    return width;
}
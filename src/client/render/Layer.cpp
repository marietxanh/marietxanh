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
	setLayerArray(text_file_name);
        setSpritesPositions();
        cout << "Layer loaded" << endl;
}

void Layer::setLayerArray(char* text_file_name)
{
    std::cout << "Accessing text file " << text_file_name << std::endl;
    ifstream file_access(text_file_name);
    if(!file_access)
    {
        std::cout << "Cannot load " << text_file_name << std::endl;
        exit(EXIT_FAILURE);
    }
    string line;
    int k = 0;
    getline(file_access, line);
    string width_s, height_s, tile_width_s, tile_height_s;
    do
    {
        switch(k)
        {
                case 1:
                        width_s = line.substr(6);
                        width = stoi(width_s);
                        break;
                case 2:
                        height_s = line.substr(7);
                        height = stoi(height_s);
                        break;
                case 3:
                        tile_width_s = line.substr(10);
                        tile_width = stoi(tile_width_s);
                        break;
                case 4:
                        tile_height_s = line.substr(11);
                        tile_height = stoi(tile_height_s);
                        break;
        }
        k++;
        getline(file_access, line);
    }while(line != "[tilesets]");

    if(height != 0 && width != 0 && tile_height != 0 && tile_width != 0) cout << "Settings loaded" << endl;

    k = 1;
    string image_name_s;
    do
    {
        size_t found = line.find('.');
        size_t temp = line.find('=') + 1;
        string::size_type sz;

        if(found != string::npos)
        {
            image_name_s = line.substr(temp, found - temp);
        }

        if((string)(this->type_layer) == "Lands"){
            found = image_name_s.find("lands");
            if(found != string::npos){
                image_name_s = "res/" + image_name_s + ".png";
                this->pack_textures.loadTextures(image_name_s, k);
            }
        }

        else if((string)(this->type_layer) == "Buildings"){
            found = image_name_s.find("buildings");
            if(found != string::npos){
                image_name_s = "res/" + image_name_s + ".png";
                this->pack_textures.loadTextures(image_name_s, k);
            }
        }
        k++;
        getline(file_access, line);
    }while(line != "\0");

    if((string)(this->type_layer) == "Lands"){
        do{getline(file_access, line);}
        while(line != "type=Lands");
    }
    else if((string)(this->type_layer) == "Buildings"){
        do{getline(file_access, line);}
        while(line != "type=Buildings");
    }

    do{getline(file_access, line);}
    while(line != "data=");

    size_t temp, found;
    string::size_type sz;
    string digit_s;

    layer_array.resize(height);
    for(int i(0); i < getHeight(); i++)
    {
        getline(file_access, line);
        found = 0;
        temp = 0;
        layer_array[i].resize(width);
        for(int j(0); j < getWidth(); j++)
        {

            found = line.find(',', found + 1);
            if(found != string::npos)
            {
                digit_s = line.substr(temp, found - temp);

                layer_array[i][j] = stoi(digit_s, &sz);
                cout << layer_array[i][j] << " ";
                temp = found + 1;
            }
        }
        if(i < height - 1) cout << endl;
    }
    found = line.find('\n');
    digit_s = line.substr(temp, found - temp);
    layer_array[getHeight() - 1][getWidth() - 1] = stoi(digit_s, &sz);
    cout << layer_array[getHeight() - 1][getWidth() - 1] << endl;

    file_access.close();
    cout << text_file_name << " closed" << endl;
}

void Layer::setSpritesPositions()
{
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

int Layer::getLayer_array(int i, int j) const
{
    return layer_array[i][j];
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

int Layer::getTile_height() const
{
    return tile_height;
}

int Layer::getTile_width() const
{
    return tile_width;
}


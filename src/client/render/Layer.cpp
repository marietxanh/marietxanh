<<<<<<< HEAD
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
=======
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Layer.h"
#include <fstream>
#include <iostream>
using namespace render;
using namespace std;

Layer::Layer()
{
    
}
Layer::Layer(string text_file_name, string type_layer)
{
    tileset = new TileSet();
    this->text_file_name = text_file_name;
    this->type_layer = type_layer;
    this->getFileTextData(text_file_name);
}
Layer::~Layer ()
{
    delete tileset;
}
Surface Layer::getSurface () const
{
    return this->surface;
}
TileSet* Layer::getTileSet () const
{
    return tileset;
}
void Layer::setSurface ()
{
    int nb;
    for (int i(0); i < height; ++i)
    {
            for (int j(0); j < width; ++j)
            {
                nb = surface.getLayerArray(i, j);
                surface.setQuadPosition(surface.getQuad(i, j), i, j, tile_width, tile_height, tileset->getTile(nb)->getWidth(), tileset->getTile(nb)->getHeight());
                surface.setQuadTextureCoordinates(surface.getQuad(i, j), tileset->getTile(nb)->getWidth(), tileset->getTile(nb)->getHeight());
            }
    }
}

void Layer::getFileTextData (std::string& text_file_name)
{
    /*fonction qui va chercher le fichier txt definit les parametres du tableau de vertex*/
    cout << "Accessing text file " << text_file_name << endl;
    ifstream file_access(text_file_name);
    if(!file_access) cout << "Cannot load " << text_file_name << endl;
    string line;
    int k = 0;
    getline(file_access, line);
    
    /*recherche des dimensions de la map*/
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
    do
    {
        switch(k)
        {
<<<<<<< HEAD
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
=======
            case 1:
                this->setWidth(stoi(line.substr(6)));
                break;
            case 2:
                this->setHeight(stoi(line.substr(7)));
                break;
            case 3:
                this->setTile_width(stoi(line.substr(10)));
                break;
            case 4:
                this->setTile_height(stoi(line.substr(11)));
                break;
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
        }
        k++;
        getline(file_access, line);
    }while(line != "[tilesets]");
<<<<<<< HEAD

    if(height != 0 && width != 0 && tile_height != 0 && tile_width != 0) cout << "Settings loaded" << endl;

    k = 1;
    string image_name_s;
=======
    
    surface.initQuads(width, height);
    
    string image_name;
    int image_width = 0, image_height = 0;
    getline(file_access, line);
   
    /*recherche des textures utilisees pour construire la carte que l'on souhaite
     afficher a l'ecran*/
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
    do
    {
        size_t found = line.find('.');
        size_t temp = line.find('=') + 1;
<<<<<<< HEAD
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
=======
        string image_width_s, image_height_s;
        std::string::size_type sz;
        if (found!=std::string::npos)
        {
            image_name = line.substr(temp, found - temp);
            temp = found + 1;
        }    
        found = line.find(',');
        temp = found + 1;
        found = line.find(',', found + 1);
        if (found!=std::string::npos)
        {
            image_width_s = line.substr(temp, found - temp);
            image_width = std::stoi (image_width_s,&sz);
            temp = found + 1;
        }
        found = line.find(',', found + 1);
        if (found!=std::string::npos)
        {
            image_height_s = line.substr(temp, found - temp);
            image_height = std::stoi (image_height_s,&sz);
        }
        tileset->setTile(image_name, image_width, image_height);        
        surface.loadTexture(image_name);
        getline(file_access, line);
    }while(line != "\0");
    
    /*deux possibilites:
        soit on charge le calque des terrains qui sont des elements non modifiables
        
        soit on charge le calque des batiments qui sont des elements modifiables
        (la capture d'un batiment implique le changement de couleur de ce dernier)*/
    if(type_layer == "Lands")
    {
        do{getline(file_access, line);}
        while(line != "type=Lands");
    }
    else if(type_layer == "Buildings")
    {
        do{getline(file_access, line);}
        while(line != "type=Buildings");
    }
    do{getline(file_access, line);}
    while(line != "data=");
    
    /*on redimensionne le tableau*/
    surface.setLayerArray(height, width);
    
    /*on ajoute dans chaque case de ce tableau le meme numero que celui du 
     fichier texte*/

    size_t temp = 0;
    size_t found = 0;
    std::string::size_type sz;
    int digit;
    string digit_s;
    for(int i(0); i < height; i ++)
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
    {
        getline(file_access, line);
        found = 0;
        temp = 0;
<<<<<<< HEAD
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

=======
        for(int j(0); j < width; j++)
        {
            //if(i < height && j < width)
            found=line.find(',',found+1);
            if (found!=std::string::npos)
            {
                digit_s = line.substr(temp, found - temp);
                digit = std::stoi (digit_s,&sz);
                temp = found + 1;
                surface.addValue(digit, i, j);
            } 
        }
    }
    found=line.find('\n');
    digit_s = line.substr(temp, found - temp);
    digit = std::stoi (digit_s,&sz);
    surface.addValue(digit, height - 1, width - 1);
    /*fermeture du fichier texte contenant les informations de la carte*/   
    file_access.close();
} 

int Layer::getWidth() const
{
    return this->width;
}

int Layer::getHeight() const
{
    return this->height;
}

void Layer::setWidth(int width)
{
    this->width = width;
}

void Layer::setHeight(int height)
{
    this->height = height;
}

void Layer::setTile_width(int tile_width)
{
    this->tile_width = tile_width;
}

void Layer::setTile_height(int tile_height)
{
    this->tile_height = tile_height;
}
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
int Layer::getTile_height() const
{
    return tile_height;
}
<<<<<<< HEAD

int Layer::getTile_width() const
{
    return tile_width;
}

=======
int Layer::getTile_width() const
{
    return tile_width;
}
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42

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
            for (int j(0); j < width; ++j)
            {
                nb = surface.getLayerArray(i, j);
                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = surface.getQuad(i, j);

                // on définit ses quatre coins
                surface.setQuadPosition(quad, i, j, tile_width, tile_height, tileset->getTile(nb)->getWidth(), tileset->getTile(nb)->getHeight());

                // on définit ses quatre coordonnées de texture
                surface.setQuadTextureCoordinates(quad, tileset->getTile(nb)->getWidth(), tileset->getTile(nb)->getHeight());

            }
}

void Layer::getFileTextData (std::string& text_file_name)
{
    /*fonction qui va chercher le fichier txt definit les parametres du tableau de vertex*/
    string text_file = text_file_name;
    cout << "Access to text file " << text_file << endl;
    ifstream file_access(text_file);
    /*inserer un CHECK pour verifier l'ouverture du fichier*/
    if(!file_access) cout << "Cannot load " << text_file << endl;
    string line;
    int k = 0;
    getline(file_access, line);
    
    /*recherche des dimensions de la map*/
    do
    {
        switch(k)
        {
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
        }
        k++;
        getline(file_access, line);
    }while(line != "[tilesets]");
    
    this->getSurface().initQuads(width, height);
    
    string image_name;
    int image_width = 0, image_height = 0;
    getline(file_access, line);
   
    /*recherche des textures utilisees pour construire la carte que l'on souhaite
     afficher a l'ecran*/
    do
    {
        size_t found = line.find('.');
        size_t temp = line.find('=') + 1;
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
    
    cout << line << endl;
    
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
    
    cout << line << endl;
    
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
    {
        getline(file_access, line);
        found = 0;
        temp = 0;
        for(int j(0); j < width; j++)
        {
            //if(i < height && j < width)
            found=line.find(',',found+1);
            if (found!=std::string::npos)
            {
                digit_s = line.substr(temp, found - temp);
                cout << digit_s << " ";
                digit = std::stoi (digit_s,&sz);
                //cout << digit << " ";
                temp = found + 1;
                surface.addValue(digit, i, j);
            } 
        }
        if(i != (height - 1)) cout << endl;
    }
    found=line.find('\n');
    digit_s = line.substr(temp, found - temp);
    digit = std::stoi (digit_s,&sz);
    cout << digit << endl;
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
int Layer::getTile_height() const
{
    return tile_height;
}
int Layer::getTile_width() const
{
    return tile_width;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Layer.h"
#include <fstream>
using namespace render;
using namespace std;

Layer::Layer(string& text_file_name)
{
    surface = new Surface();
    tileset = new TileSet();
}
Layer::~Layer ()
{
    delete surface;
    delete tileset;
}
Surface* Layer::getSurface () const
{
    return this->surface;
}
void Layer::setSurface ()
{
    int nb;
    for (int i(0); i < width; ++i)
            for (int j(0); j < height; ++j)
            {
                nb = this->getLayer_array()[i][j];
                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = this->surface->getQuad(i, j);

                // on définit ses quatre coins
                this->getSurface()->setQuadPosition(quad, i, j, tile_width, tile_height, )

                // on définit ses quatre coordonnées de texture
                this->getSurface()->setQuadTextureCoordinates(quad, nb, i, j, this->getTileSet()->getTile(nb)->getWidth(), this->getTileSet()->getTile(nb)->getHeight());

            }
}

void Layer::getFileTextData (std::string& text_file_name)
{
    /*fonction qui va chercher le fichier txt correspondant au fichier png
     et permet de definir les parametres du tableau de vertex*/
    string text_file = "res/" + text_file_name + ".txt";
    ifstream file_access(text_file);
    /*inserer un CHECK pour verifier l'ouverture du fichier*/
    string line;
    int k = 0;
    getline(file_access, line);
    do
    {
        switch(k)
        {
            case 1:
                this->setWidth(int(line.substr(6)));
                break;
            case 2:
                this->setHeight(int(line.substr(7)));
                break;
            case 3:
                this->setTile_width(int(line.substr(10)));
                break;
            case 4:
                this->setTile_height(int(line.substr(11)));
                break;
        }
        k++;
    }while(getline(file_access, line) != "[tilesets]");
    
    this->getSurface()->initQuads(width, height);
    size_t found, temp;
    string image_name, image_width, image_height;
    getline(file_access, line);
    temp = line.find('=') + 1;
    found = -1;
    do
    {
        found=line.find('.',found+1,6);
        if (found!=std::string::npos)
        {
            image_name = line.substr(temp, found - temp);
            temp = found + 1;
        }    
        found=line.find(',',found+1,6);
        if (found!=std::string::npos)
        {
            image_width = line.substr(temp, found - temp);
            temp = found + 1;
        }
        found=line.find(',',found+1,6);
        if (found!=std::string::npos)
        {
            image_height = line.substr(temp, found - temp);
        }
        this->getTileSet()->setTile(image_name, image_width, image_height);
        this->getSurface()->loadTexture(image_name);
    }while(getline(file_access, line) != "");
    if(this->getType_layer() == "Lands")
    {
        while(getline(file_access, line) != "type=Lands");
    }
    else if(this->getType_layer() == "Buildings")
    {
        while(getline(file_access, line) != "type=Builidings");
    }
    while(getline(file_access, line) != "data=");
    this->getLayer_array().resize(this->getHeight());

    for(int i(0); i < this->getLayer_array().size(); i ++)
    {
        temp = 0;
        found = -1;
        this->getLayer_array()[i].resize(this->getWidth());
        for(int j(0); j < this->getLayer_array().size(); j++)
        {
            if(i != this->)
            found=line.find(',',found+1,6);
            if (found!=std::string::npos)
            {
                this->getLayer_array()[i][j] = int(line.substr(temp, found - temp));
            }    
        }
    }
        
    file_access.close();    this->getLayer_array().push_back();
            found=line.find(',');
            if (found!=std::string::npos)
            {
                this->getLayer_array()[i].push_back()line.substr(temp, found - temp);
                temp = found + 1;
            }
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


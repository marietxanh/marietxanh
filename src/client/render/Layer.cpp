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
    surface->loadTexture(file_name);
    int nb;
    for (int i(0); i < width; ++i)
            for (int j(0); j < height; ++j)
            {
                nb = this->getLayer_array()[i][j];
                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = this->surface->getQuad(i, j);

                // on définit ses quatre coins
                this->getSurface()->setQuadPosition(quad, i, j, tile_width, tile_height, )

                nb
                // on définit ses quatre coordonnées de texture
                this->getSurface()->setQuadTextureCoordinates(quad, i, j, this->getTileSet()->getTile(nb)->getWidth(), this->getTileSet()->getTile(nb)->getHeight());

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
                this->tile_width = int(line.substr(10));
                break;
            case 4:
                this->tile_height = int(line.substr(11));
                break;
        }
        k++;
    }while(getline(file_access, line) != "[tilesets]");
    
    this->getSurface()->initQuads(width, height);
    
    
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


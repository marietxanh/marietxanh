/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Tile.h"
using namespace render;
using namespace std;

Tile::Tile ()
{
    
}
Tile::Tile (string& adress_file, int width, int height)
{
    this->adress_file = adress_file;
    this->width = width;
    this->height = height;
}
Tile::~Tile ()
{
    
}
int Tile::getWidth () const
{
    return this->width;
}
int Tile::getHeight () const
{
    return this->height;
}
string Tile::getAdressFile () const
{
    return this->adress_file;
}


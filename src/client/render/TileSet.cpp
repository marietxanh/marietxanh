/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TileSet.h"
using namespace render;

TileSet::TileSet()
{
    
}
TileSet::~TileSet()
{
    for(int i(0); i < int(this->tiles_array.size()); i++)
    {
        delete this->tiles_array[i];
        this->tiles_array[i] = 0;
    }
}
Tile* TileSet::getTile (int i) const
{
    return this->tiles_array[i];
}
void TileSet::setTile (std::string& name, int width, int height)
{
    this->tiles_array.push_back(new Tile(name, width, height));

}
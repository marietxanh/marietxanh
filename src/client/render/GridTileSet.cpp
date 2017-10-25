/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "GridTileSet.h"
using namespace render;
using namespace status;

GridTileSet::GridTileSet ()
{

}
GridTileSet::~GridTileSet ()
{
    for(int i(0); i < sizeof(lands); ++i)
    {
        delete lands[i];
        lands[i] = 0;
    }
}
int GridTileSet::getCellWidth () const
{
    
}
int GridTileSet::getCellHeight () const
{
    
}
std::string GridTileSet::getImageFile () const
{
    
}
Tile* GridTileSet::getTile (Element* element)
{
    
}
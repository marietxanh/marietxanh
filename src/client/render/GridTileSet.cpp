/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "GridTileSet.h"

#define ORANGE_BUILDING "../../res/advance_wars_sprites_buildings/advance_wars_sprites_buildings_orange"
#define BLUE_BUILDING "../../res/advance_wars_sprites_buildings/advance_wars_sprites_buildings_blue"
#define GREEN_BUILDING "../../res/advance_wars_sprites_buildings/advance_wars_sprites_buildings_green"
#define YELLOW_BUILDING "../../res/advance_wars_sprites_buildings/advance_wars_sprites_buildings_yellow"

using namespace render;
using namespace status;
using namespace std;

GridTileSet::GridTileSet ()
{

}
GridTileSet::~GridTileSet ()
{
    for(int i(0); i < sizeof(lands); ++i)
    {
        for(int j(0); j < sizeof(lands[i]); j++)
        {
            delete lands[i][j];
            lands[i][j] = 0;
        }
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
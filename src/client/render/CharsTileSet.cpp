/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CharsTileSet.h"

#define ORANGE_UNITS "../../res/advance_wars_sprites_units/advance_wars_units_orange"
#define BLUE_UNITS "../../res/advance_wars_sprites_units/advance_wars_units_blue"
#define GREEN_UNITS "../../res/advance_wars_sprites_units/advance_wars_units_green"
#define YELLOW_UNITS "../../res/advance_wars_sprites_units/advance_wars_units_yellow"
using namespace render;
using namespace status;
using namespace std;

CharsTileSet::CharsTileSet ()
{
    
}
CharsTileSet::~CharsTileSet ()
{
    for(int i(0); i < sizeof(units); ++i)
    {
        delete units[i];
        units[i] = 0;
    }
}
int CharsTileSet::getCellWidth () const
{
    return units[1]->getCellWidth();
}
int CharsTileSet::getCellHeight () const
{
    return units[1]->getCellHeight();
}
string CharsTileSet::getImageFile () const
{
    
}
Tile* CharsTileSet::getTile (Element* element)
{
    
}


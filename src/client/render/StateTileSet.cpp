/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "StateTileSet.h"
using namespace render;
using namespace std;

StateTileSet::StateTileSet ()
{
    
}
StateTileSet::~StateTileSet ()
{
    for(int i(0); i < sizeof(chars); ++i)
    {
        delete chars[i];
        chars[i] = 0;
    }
}
int StateTileSet::getCellHeight () const
{
    
}
int StateTileSet::getCellWidth () const
{
    
}
string StateTileSet::getImageFile ()
{
    
}
Tile* StateTileSet::getCharTile (char character)
{
    
}


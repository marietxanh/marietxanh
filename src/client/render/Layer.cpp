/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Layer.h"
using namespace render;


Layer::~Layer ()
{
    delete surface;
    delete tileset;
}
Surface* Layer::getSurface () const
{
    return this->surface;
}
void Layer::setSurface (Surface* surface)
{
    surface->loadTexture("res/test_render.png");
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementTabLayer.h"
using namespace render;
using namespace status;

ElementTabLayer::ElementTabLayer (ElementTab* element_tab)
{
    this->element_tab = element_tab;
}
ElementTabLayer::~ElementTabLayer ()
{
    delete element_tab;
}
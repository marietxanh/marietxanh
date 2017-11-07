/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementTabLayer.h"
#include <iostream>
#include <string>

using namespace status;
using namespace render;

ElementTabLayer::ElementTabLayer(char* text_file_name, char* type_layer) : Layer(text_file_name, type_layer)
{
    
}
ElementTab* ElementTabLayer::getElement_tab() const
{
    return element_tab;
}


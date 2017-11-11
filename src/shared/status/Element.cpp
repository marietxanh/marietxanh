/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include "../status/Element.h"
using namespace status;

Element::Element(TypeID id)
{
        setType_id(id);
}

Element::Element(Element* old_element)
{
    this->height_position = old_element->height_position;
    this->width_position = old_element->width_position;
    this->type_id = old_element->type_id;
}

Element::~Element()
{
    
}

TypeID Element::getType_id() const
{
    return this->type_id;
}

void Element::setType_id(TypeID id)
{
    type_id = id;
}

int Element::getHeight_position() const
{
    return this->height_position;
}

int Element::getWidth_position() const
{
    return this->width_position;
}
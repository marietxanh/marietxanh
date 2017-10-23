/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../status/Element.h"
using namespace status;

Element::Element(TypeID id)
{
        setType_id(id);
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
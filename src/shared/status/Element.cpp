/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../status/Element.h"
using namespace status;

Element::Element(int abs, int ord, TypeID id): abscissa(abs), ordinate(ord)
{
        setType_id(id);
}

Element::~Element()
{
    
}

int Element::getAbscissa() const 
{
    return abscissa;
}

void Element::setAbscissa(int abscissa)
{
    this->abscissa = abscissa;
}

int Element::getOrdinate() const
{
    return ordinate;
}

void Element::setOrdinate(int ordinate)
{
        this->ordinate = ordinate;
}

TypeID Element::getType_id() const
{
    return this->type_id;
}

void Element::setType_id(TypeID id)
{
    type_id = id;
}
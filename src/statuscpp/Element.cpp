/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../status/Element.h"
#include "../status/TypeID.h"

Element::Element(int abs, int ord, int fuel, int load):abscissa(abs), ordinate(ord), refuel(fuel), reload(load)
{
    
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

int Element::getRefuel() const
{
        return refuel;
}

void Element::setRefuel(int refuel)
{
        this->refuel = refuel;
}

int Element::getReload() const
{
        return reload;
}

void Element::setReload(int reload)
{
        this->reload;
}

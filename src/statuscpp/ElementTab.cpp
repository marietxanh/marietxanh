#include"../status/ElementTab.h"
using namespace status;
using namespace std;

ElementTab::ElementTab (size_t width, size_t height, TypeTransport type_transport, TypeUnits type_unit, TypeID type_id): width(width), height(height)
{
    if(type_transport == -1){
        for(int i(0); i < height; i++)
        {
                array.push_back(vector<Element*>());
                for(int j(0); j < width; j++)
                {
                    array[i].push_back(new Unit(j, i, type_unit, type_id));
                }
        }
    }
    else
    {
        for(int i(0); i < height; i++)
        {
                array.push_back(vector<Element*>());
                for(int j(0); j < width; j++)
                {
                    array[i].push_back(new Transport(j, i, type_transport, type_unit, type_id));
                }
        }
    }
}

ElementTab::ElementTab (size_t width, size_t height, TypeBuilding type_building, TypeLand type_land, TypeID type_id): width(width), height(height)
{
    if (type_building == -1)
    {
        for(int i(0); i < height; i++)
        {
                array.push_back(vector<Element*>());
                for(int j(0); j < width; j++)
                {
                    array[i].push_back(new Land(j, i, type_land, type_id));
                }
        }
    }
    else
    {
        for(int i(0); i < height; i++)
        {
                array.push_back(vector<Element*>());
                for(int j(0); j < width; j++)
                {
                    array[i].push_back(new Building(j, i, type_building, type_land, type_id));
                }
        }
    }
}

ElementTab::~ElementTab()
{
        for(int i(0); i < sizeof(array); i++)
        {
                for(int j(0); j < sizeof(array[i]); j++)
                {
                        delete array[i][j];
                        delete array[i][j];
                }
        }
}

size_t const ElementTab::getWidth()
{
        return width;
}

size_t const ElementTab::getHeight()
{
        return height;
}

void ElementTab::resize(size_t width, size_t height)
{
        this->width = width;
        this->height = height;
}

Element* const ElementTab::getElement(int i, int j)
{
        return array[i][j];
}

void ElementTab::setElement(int i, int j, Element* element)
{
        element->setAbscissa(j);
        element->setOrdinate(i);
}

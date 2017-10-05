#include"../status/ElementTab.h"
using namespace status;
using namespace std;

ElementTab::ElementTab(size_t width, size_t height, TypeID id): width(width), height(height)
{
    if(id == LAND){
        for(int i(0); i < height; i++)
        {
                array.push_back(vector<Element*>());
                for(int j(0); j < width; j++)
                {
                    array[i].push_back(new Land(j, i, LAND));
                }
        }
    }
    else {
        for(int i(0); i < height; i++)
        {
                array.push_back(vector<Element*>());
                for(int j(0); j < width; j++)
                {
                    array[i].push_back(new Unit(j, i, UNIT));
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

size_t ElementTab::getWidth() const
{
        return width;
}

size_t ElementTab::getHeight() const
{
        return height;
}

void ElementTab::resize(size_t width, size_t height)
{
        this->width = width;
        this->height = height;
}

Element* ElementTab::getElement(int i, int j) const
{
        return array[i][j];
}

void ElementTab::setElement(int i, int j, Element* element)
{
        element->setAbscissa(j);
        element->setOrdinate(i);
}

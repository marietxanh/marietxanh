#include "../status/ElementTab.h"
#include <iostream>
using namespace status;
using namespace std;

ElementTab::ElementTab (size_t width, size_t height, TypeID type_id): width(width), height(height)
{
    // rewrite with a resize function
    array.resize(width);
    for(int i(0); i < width; i++)
        {
            array[i].resize(height);
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

Element* const ElementTab::getElement(int i, int j)
{
        return array[i][j];
}

void ElementTab::setElement(int i, int j, Element* element)
{
    if(array[i][j] == NULL) array[i][j] = element;
    else printf("An element is already using this space.\n");
}

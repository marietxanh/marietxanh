#include "../status/ElementTab.h"
#include <iostream>
using namespace status;
using namespace std;

ElementTab::ElementTab (int width, int height, TypeID type_id): width(width), height(height)
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
     
}

int ElementTab::getWidth() const
{
        return width;
}

int ElementTab::getHeight() const
{
        return height;
}

Element* ElementTab::getElement(int i, int j)
{
        return array[i][j];
}

void ElementTab::setElement(int i, int j, Element* element)
{
    if(array[i][j] == NULL) array[i][j] = element;
    else printf("An element is already using this space.\n");
}

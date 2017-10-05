#include"../status/ElementTab.h"

ElementTab::ElementTab(size_t width, size_t height): this->width(width), this->height(height)
{
        for(int i(0); i < height; i++)
        {
                array.push_back(vector<Element*>);
                for(int j(0); j < sizeof(width); j++)
                {
                        array[i].push_back(new Element(j, i, 0, 0));
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
                delete array[i];
                array[i] = 0;
        }
}

size_t ElementTab::getWidth() const
{
        return this->width;
}

size_t ElementTab::getHeigth() const
{
        return this->height;
}

void ElementTab::add(Element* element)
{
        map->push_back(element);
}

void ElementTab::resize(size_t width, size_t height)
{
        this->width = width;
        this->height = height;
}

Element* ElementTab::getElement(int i, int j)
{
        return map[i][j];
}

void ElementTab::setElement(int i, int j, Element* element)
{
        map[i][j] = element;
}

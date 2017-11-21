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

ElementTabLayer::ElementTabLayer(ElementTab* element_tab) : Layer()
{
    this->element_tab = element_tab;
    this->setTextures();
    this->setSpritesPositions();
    std::cout << std::endl;
}

ElementTabLayer::~ElementTabLayer()
{
    delete element_tab;
}
ElementTab* ElementTabLayer::getElement_tab() const
{
    return element_tab;
}

void ElementTabLayer::setSpritesPositions()
{
    this->setHeight(((int)(this->element_tab->getTab().size())));
    this->setWidth(((int)(this->element_tab->getTab()[0].size())));
    this->setSpritesTabDim();
    //std::cout << "height : " << height << " width : " << width << std::endl;
    for(int i(0); i < height; i++)
    {
            for(int j(0); j < width; j++)
            {
                if(element_tab->getElement(i, j) > 0){
                    int width_t = (int)(this->getTextures_pack()->getText(element_tab->getLayerArray(i, j)).getSize().x);
                    int height_t = (int)(this->getTextures_pack()->getText(element_tab->getLayerArray(i, j)).getSize().y);
                    //std::cout << width_t << '\t' << height_t << '\t';
                    this->getSprite(i, j).setPosition(sf::Vector2f(16 * j - (width_t - 16), 16 * i - (height_t - 16)));
                    //this->getSprite(i, j).setPosition(sf::Vector2f(16,48));
                    this->getSprite(i, j).setTexture(this->getTextures_pack()->getText(element_tab->getLayerArray(i, j)));
                }
                else
                {
                    //std::cout << "-1\t-1\t";
                    this->getSprite(i ,j).setPosition(sf::Vector2f(16 * j, 16 * i));
                }
            }
        //std::cout << std::endl;

    }
    std::cout << "setSpritesPositions OK" << std::endl;
}

void ElementTabLayer::setTextures()
{
    this->getTextures_pack()->setTexturesArray(this->element_tab->getTextures_references());
}


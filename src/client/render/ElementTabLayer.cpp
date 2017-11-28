/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementTabLayer.h"
#include "../shared/status.h"
#include <iostream>
#include <typeinfo>
#include <string>

using namespace status;
using namespace render;

ElementTabLayer::ElementTabLayer(ElementTab* element_tab) : Layer()
{
    this->element_tab = element_tab;
    this->setTextures();
    std::cout << "setTextures OK" << std::endl;
    this->setSpritesPositions();
    std::cout << "setSprites OK" << std::endl;
}

ElementTabLayer::~ElementTabLayer()
{
    
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
    for(int i(0); i < height; i++)
    {
            for(int j(0); j < width; j++)
            {
                if(element_tab->getElement(i, j) != NULL)
                {
                    if(element_tab->getElement(i, j)->getType_id() == LAND)
                    {
                        if(element_tab->getLayerArray(i, j) > 0){
                            int width_t = (int)(this->getTextures_pack()->getText(element_tab->getLayerArray(i, j)).getSize().x);
                            int height_t = (int)(this->getTextures_pack()->getText(element_tab->getLayerArray(i, j)).getSize().y);
                            this->getSprite(i, j).setPosition(sf::Vector2f(16 * j - (width_t - 16), 16 * i - (height_t - 16)));
                            this->getSprite(i, j).setTexture(this->getTextures_pack()->getText(element_tab->getLayerArray(i, j)));
                        }
                    }
                    else if(element_tab->getElement(i, j)->getType_id() == UNIT)
                    {
                        this->getSprite(i, j).setPosition(sf::Vector2f(16 * j, 16 * i));
                        if(((status::Unit*)(element_tab->getElement(i, j)))->getType_unit() != TRANSPORT)
                        {
                            int offset = 0;
                            if(((status::Unit*)(element_tab->getElement(i, j)))->getTeam() == ORANGE) offset = 0;
                            else if(((status::Unit*)(element_tab->getElement(i, j)))->getTeam() == BLUE) offset = 13;
                            this->getSprite(i, j).setTexture(this->getTextures_pack()->getText(((status::Unit*)(element_tab->getElement(i, j)))->getType_unit() + offset - 1));
                        }
                        else if(((status::Unit*)(element_tab->getElement(i, j)))->getType_unit() == TRANSPORT)
                        {
                            this->getSprite(i, j).setTexture(this->getTextures_pack()->getText(((status::Transport*)(element_tab->getElement(i, j)))->getType_transport() - 1));
                        }
                    }
                    else
                    {
                        std::cout << "Problem id" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                }
            }
    }
}

void ElementTabLayer::setTextures()
{
    this->getTextures_pack()->setTexturesArray(element_tab->getTextures_references());
}

void ElementTabLayer::refresh_array ()
{ 
    for(int i(0); i < height; i++)
    {
        for(int j(0); j < width; j++)
        {
            if(this->element_tab->getElement(i, j) != NULL)
            {
                this->getSprite(i, j).setPosition(sf::Vector2f(16 * j, 16 * i));
                if(((status::Unit*)(element_tab->getElement(i, j)))->getType_unit() != TRANSPORT)
                {
                    int offset = 0;
                    if(((status::Unit*)(element_tab->getElement(i, j)))->getTeam() == ORANGE) offset = 0;
                    else if(((status::Unit*)(element_tab->getElement(i, j)))->getTeam() == BLUE) offset = 12;
                    this->getSprite(i, j).setTexture(this->getTextures_pack()->getText(((status::Unit*)(element_tab->getElement(i, j)))->getType_unit() + offset - 1));
                }
                else if(((status::Unit*)(element_tab->getElement(i, j)))->getType_unit() == TRANSPORT)
                {
                    this->getSprite(i, j).setTexture(this->getTextures_pack()->getText(((status::Transport*)(element_tab->getElement(i, j)))->getType_transport() - 1));
                }
            }
        }
    }
}


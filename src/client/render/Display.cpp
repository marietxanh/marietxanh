/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Display.h"
#include <iostream>
using namespace std;

namespace render{
    Display::Display (status::State* state)
    {
        this->state = state;
        lands = new ElementTabLayer(state->getLands());
        cout << "lands layer OK" << endl;
        buildings = new ElementTabLayer(state->getBuildings());
        cout << "buildings layer OK" << endl;
        units = new ElementTabLayer(state->getUnits());
        cout << "units layer OK" << endl;
        window.create(sf::VideoMode(state->getWidth() * 16, state->getHeight() * 16), "RenderWindow");
        window.setFramerateLimit(30);
    }
    Display::~Display ()
    {
        
    }
    void Display::refreshWindow ()
    {
        window.clear();
        for(int i(0); i < state->getHeight(); i++)
		{
			for(int j(0); j < state->getWidth(); j++)
			{
                            /*dessine dans l'ordre les differentes "couches"
                             d'abord les terrains, ensuite les batiments puis les unites*/
                            if(state->getLands()->getLayerArray(i, j) > 0)
				window.draw(lands->getSprite(i ,j));
                            if(state->getBuildings()->getLayerArray(i, j) > 0)
				window.draw(buildings->getSprite(i, j));
                            if(state->getUnits()->getElement(i, j) != NULL)
				window.draw(units->getSprite(i, j));
			}
                        
		}
        window.display();
    }
    
    const sf::RenderWindow& Display::getWindow () const
    {
        return this->window;
    }
    checkEvent (const sf::Event& event);
    void closeWindow ();
};


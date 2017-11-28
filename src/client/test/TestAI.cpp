/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <SFML/Graphics/RenderWindow.hpp>
#include <unistd.h>
#include "TestAI.h"

#define CHECK(expr) \
    if (!(expr)) throw std::runtime_error("Echec " #expr);

using namespace std;
using namespace engine;
using namespace status;
using namespace render;
using namespace ai;
using namespace sf;

void TestAI::testAI()
{
	cout<<"AI en jeu\n"<< endl;

	string file_name = "res/test_render.txt";
        Engine* moteur = new Engine();
        moteur->addCommand(new LoadMap(file_name));
        moteur->update();
        ElementTabLayer *lands = new ElementTabLayer(moteur->getState()->getLands());
        ElementTabLayer *buildings = new ElementTabLayer(moteur->getState()->getBuildings());
        ElementTabLayer *units = new ElementTabLayer(moteur->getState()->getUnits());
	
	int height = moteur->getState()->getHeight();
	int width = moteur->getState()->getWidth();
	
	/*creation d'unites pour faire tourner l'intelligence artificielle*/
	for(int i(0); i <  height; i++)
	{
		for(int j(0); j < width; j++)
		{
			if(moteur->getState()->getBuildings()->getElement(i, j) != NULL)
			{
				if(((Building*)(moteur->getState()->getBuildings()->getElement(i, j)))->getType_building() == FACTORY)
				{
					moteur->addCommand(new CreateUnit(INFANTRY, i, j));
				}
			}
		}
	}
	moteur->update();
        
        sf::RenderWindow window(sf::VideoMode(moteur->getState()->getWidth() * 16, moteur->getState()->getHeight() * 16), "TestEngine");
        //window.setFramerateLimit(30);
	string move = "move";
	string attack = "attack";

	RandomAI art_int;
	art_int.addCommand(move);
        art_int.addCommand(attack);
        cout << "Window opens" << endl;
        while(window.isOpen())
        {
            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed) window.close();
                cout << "Window closed" << endl;
            }
                        
            window.clear();
            units->refresh_array();
            for(int i = 0; i < moteur->getState()->getHeight(); i++)
            {
                    for(int j(0); j < moteur->getState()->getWidth(); j++)
                    {
                        if(moteur->getState()->getLands()->getLayerArray(i, j) > 0)
                            window.draw(lands->getSprite(i ,j));
                        if(moteur->getState()->getBuildings()->getLayerArray(i, j) > 0)
                            window.draw(buildings->getSprite(i, j));
                        if(moteur->getState()->getUnits()->getElement(i, j) != NULL)
                            window.draw(units->getSprite(i, j));
                    }
            }
            
            art_int.run(moteur);
            cout << "\nend of run\n" << endl;
            sleep(2);
            window.display();
        }
}



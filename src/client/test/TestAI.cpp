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
	Display display(moteur->getState());
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
	string move = "move";
	string attack = "attack";

	RandomAI art_int;
	art_int.addCommand(move);
        art_int.addCommand(attack);
        cout << "Window opens" << endl;
        while(display.getWindow().isOpen())
        {
            sf::Event event;
            while(display.checkEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {
                    display.closeWindow();
                    cout << "Window closed" << endl;
                }
            }
            display.getUnits()->refresh_array();
            moteur->addCommand(new ResetUnits());
            moteur->update();
            display.refreshWindow();
            sleep(2);           
            art_int.run(moteur);
            cout << "--------------------------------------------" << endl;
        }
}



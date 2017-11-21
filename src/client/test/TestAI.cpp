/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <SFML/Graphics/RenderWindow.hpp>

#include "TestAI.h"

#define CHECK(expr) \
    if (!(expr)) throw std::runtime_error("Echec " #expr);

using namespace std;
using namespace engine;
using namespace status;
using namespace ai;

void TestAI::testAI()
{
	cout<<"AI en jeu\n"<< endl;
	vector<Command*> lCommandUnit;

	string file_name = "res/test_render.txt";
    Engine* moteur = new Engine();

	moteur->addCommand(new LoadMap(file_name));
	moteur->update();
	
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

	art_int.run(moteur);

}



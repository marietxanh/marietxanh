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

	
	moteur->addCommand(new CreateUnit(INFANTRY, 2, 1));
	moteur->update();

	lCommandUnit.push_back(new MoveUnit(2,1,3,4));
	lCommandUnit.push_back(new MoveUnit(2,1,1,2));
	lCommandUnit.push_back(new MoveUnit(2,1,4,3));			
	RandomAI david(lCommandUnit.size());
	david.setlist(lCommandUnit);

	moteur->addCommand(new LoadMap(file_name));
	moteur->update();
	/* creation unites par les usines */
	/* setlist() */

	david.run(moteur);
	cout<<"1er coup\n"<< endl;

	david.set_randgen(5);
	david.run(moteur);
	cout<<"2ème coup\n"<< endl;

}



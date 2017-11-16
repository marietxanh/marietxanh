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

void TestAI::testAI(){
	cout<<"AI en jeu\n"<< endl;

	RandomAI david(5);
	string file_name = "res/test_render.txt";
    	Engine moteur(file_name);

	cout<<"1er coup\n"<< endl;
	david.run(moteur);
	cout<<"2ème coup\n"<< endl;
	david(5);
	david.run(moteur);
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <SFML/Graphics/RenderWindow.hpp>

#include "TestEngine.h"

#define CHECK(expr) \
    if (!(expr)) throw std::runtime_error("Echec " #expr);

#define PRINT(expr) \
	std::cout << expr << std::endl;

using namespace std;
using namespace engine;
using namespace status;
using namespace render;

void TestEngine::testEngine(){
    
    cout<<"Chargement du niveau"<< endl;
    string file_name = "res/test_render.txt";
    Engine *moteur = new Engine();
    moteur->addCommand(new LoadMap(file_name));
    moteur->update();
    Display display(moteur->getState());
    int k = 0;
    cout << "\nPRESS SPACE TO CHANGE STATE\n" << endl;
    while(display.getWindow().isOpen())
    {
        sf::Event event;
        while(display.checkEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::KeyReleased:
                    if(event.key.code == sf::Keyboard::Space && k == 0)
                    {
                        cout << "\n\nSpace entered : creation of two units" << endl;
                        moteur->addCommand(new CreateUnit(INFANTRY, 2, 1));
                        moteur->getState()->getUnits()->newElement(2, 3, new Unit(INFANTRY, BLUE));
			moteur->update();
						
                        CHECK(((Unit*)(moteur->getState()->getUnits()->getElement(2,1)))->getType_unit() == INFANTRY);
                        CHECK(((Unit*)(moteur->getState()->getUnits()->getElement(2,3)))->getType_unit() == INFANTRY);
                        display.getUnits()->refresh_array();
                        k++;
                        
                    }
                    else if(event.key.code == sf::Keyboard::Space && k == 1)
                    {
                        cout << "\n\nSpace entered : moving created unit" << endl;
                        moteur->addCommand(new MoveUnit(2, 1, 2, 2));
                        moteur->update();
                        CHECK(((Unit*)(moteur->getState()->getUnits()->getElement(2,1))) == NULL);
                        CHECK(((Unit*)(moteur->getState()->getUnits()->getElement(2,2)))->getType_unit() == INFANTRY);
                        display.getUnits()->refresh_array();
                        k++;
                    }
                    else if(event.key.code == sf::Keyboard::Space && k == 2)
                    {
                        cout << "\n\nSpace entered : created unit attack" << endl;
                        moteur->addCommand(new AttackUnit(2, 2, 2, 3));
                        moteur->update();
                        display.getUnits()->refresh_array();
                        k++;
                    }
                    break;
                case sf::Event::Closed:
                    display.closeWindow();
                    break;
                default:
                    break;
            }
            if(k == 3) display.closeWindow();
        }
        
        display.refreshWindow();
    }
    delete moteur;
}

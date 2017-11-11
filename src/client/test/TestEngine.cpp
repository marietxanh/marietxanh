/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <SFML/Graphics/RenderWindow.hpp>

#include "TestEngine.h"

#define CHECK(expr) \
    if (!(expr)) throw std::runtime_error("Echec " #expr);

using namespace std;
using namespace engine;
using namespace status;

void TestEngine::testEngine(){
    

    
    cout<<"Chargement du niveau\n"<< endl;
    string file_name = "../../../res/test_render.txt";
    Engine *moteur = new Engine(file_name);
    sf::Window window;
    sf::Event event;
    for(int i(0); i < 3; i++)
    {
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && i == 0)
            {
                moteur->createUnit(INFANTRY, 2, 1);
                CHECK(((Unit*)(moteur->getState()->getUnits()->getElement(2,1)))->getType_unit() == INFANTRY);
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && i == 1)
            {
                moteur->moveUnit(2, 1, 2, 2);
                CHECK(((Unit*)(moteur->getState()->getUnits()->getElement(2,1))) == NULL);
                CHECK(((Unit*)(moteur->getState()->getUnits()->getElement(2,2)))->getType_unit() == INFANTRY);
            }
            else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && i == 2)
            {
                moteur->attackUnit(2, 2, 2, 3);
            }
            
            
        }
    }
    
    delete moteur;
   
}

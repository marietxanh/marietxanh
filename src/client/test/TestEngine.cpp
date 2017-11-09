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
    
    Engine moteur;
    
    cout<<"Chargement du niveau\n"<< endl;
    moteur.getState() = new State("../../../res/test_render.txt");
    moteur.getState()->getUnits()->setElement(2, 3, new Unit(INFANTRY));
    sf::Window window;
    sf::Event event;
    for(int i(0); i < 3; i++)
    {
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && i == 0)
            {
                    moteur.addCommand(0, new CreateCharacterCommand(moteur.getState()->getBuildings()->getElement(2,1), moteur.getState()->getUnits()));
                    CHECK(((Unit*)(moteur.getState()->getUnits()->getElement(2,1)))->getType_unit() == INFANTRY);
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && i == 1)
            {
                    moteur.addCommand(0, new MoveCharCommand(moteur.getState()->getUnits()->getElement(2,1), moteur.getState()->getLands()->getElement(2,2)));
                    CHECK(((Unit*)(moteur.getState()->getUnits()->getElement(2,1))) == NULL);
                    CHECK(((Unit*)(moteur.getState()->getUnits()->getElement(2,2)))->getType_unit() == INFANTRY);
            }
            else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && i == 2)
            {
                moteur.addCommand(0, new AttackCharCommand(((Unit*)(moteur.getState()->getUnits()->getElement(2,2))), ((Unit*)(moteur.getState()->getUnits()->getElement(2,3)))));
            }
            
            
        }
    }
   
}

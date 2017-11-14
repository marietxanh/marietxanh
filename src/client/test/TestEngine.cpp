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
    string file_name = "res/test_render.txt";
    Engine moteur;
    moteur.addCommand(new LoadMap(file_name));
    moteur.update();
    sf::Window window;
    window.create(sf::VideoMode(500, 200), "TestEngine");
    int i = 0;
    cout << "\n\nPRESS SPACE TO CHANGE STATE\n" << endl;
    while(window.isOpen())
    {
        //cout << i << endl;
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::KeyReleased:
                    if(event.key.code == sf::Keyboard::Space && i == 0)
                    {
                        cout << "Space entered : creation of two units" << endl;
                        moteur.addCommand(new CreateUnit(INFANTRY, 2, 1));
                        moteur.addCommand(new CreateUnit(INFANTRY, 2, 1));
						moteur.update();
                        CHECK(((Unit*)(moteur.getState().getUnits()->getElement(2,1)))->getType_unit() == INFANTRY);
                        CHECK(((Unit*)(moteur.getState().getUnits()->getElement(2,3)))->getType_unit() == INFANTRY);
                        
                        i++;
                    }
                    else if(event.key.code == sf::Keyboard::Space && i == 1)
                    {
                        cout << "Space entered : moving created unit" << endl;
                        moteur.addCommand(new MoveUnit(2, 1, 2, 2));
						moteur.update();
                        CHECK(((Unit*)(moteur.getState().getUnits()->getElement(2,1))) == NULL);
                        CHECK(((Unit*)(moteur.getState().getUnits()->getElement(2,2)))->getType_unit() == INFANTRY);
                        i++;
                    }
                    else if(event.key.code == sf::Keyboard::Space && i == 2)
                    {
                        cout << "Space entered : created unit attack" << endl;
                        moteur.addCommand(new AttackUnit(2, 2, 2, 3));
                        i++;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
            if(i == 3) window.close();
        }
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <SFML/Graphics/RenderWindow.hpp>

#include "TestEngine.h"
#include "../../shared/engine.h"
#include "../../shared/status.h"

using namespace std;
using namespace engine;
using namespace status;

void TestEngine::testEngine(){
    
    Engine moteur;
    
    cout<<"Chargement du niveau\n"<< endl;
    moteur.getState() = new State("../../../res/test_render.txt");
    sf::Window window;
    sf::Event event;

    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Escape)
            {
                moteur.addCommand(0, (CreateCharacter*)())
            }
        }
    }
    
    moteur.addCommand(1,niveau);
    
    cout << "Sélection d'un personnage\n" << endl;
    SelectCharCommand select();
    moteur.addCommand(2,select);
    
    if(grid + (select.character.range_mvmt)== /*emlacement ennemi*/){   /*si un ennemi est à portée*/
        cout << "Attaque ennemi\n" << endl;
        AttackCharCommand attaque();
        moteur.addCommand(4,attaque);
    }
    else {
        cout << "Déplacement d'un personnage\n" << endl;
        MoveCharCommand deplacement();
        moteur.addCommand(3,deplacement);
    }
    
    cout << "Récupération des taxes\n" << endl;
    HandleBuildingCommand taxes();
    moteur.addCommand(5,taxes);
    
    cout << "Fin d'un jour\n" << endl;
    moteur.update();
   
}

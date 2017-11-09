/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "TestEngine.h"
#include "../engine.h"

using namespace std;
using namespace engine;

void TestEngine::testEngine(){
    
    Engine moteur();
    
    cout<<"Chargement du niveau\n"<< endl;
    LoadCommand niveau("../../../res/test_render.txt");
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

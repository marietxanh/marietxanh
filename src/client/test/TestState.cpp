/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "TestState.h"

using namespace std;
using namespace status;

#define CHECK(expr) \
    if (!(expr)) throw std::runtime_error("Echec " #expr);

void TestState::testState(){
    cout <<  "Test of state in game." << endl;
    /*creation d'un objet State contenant
     deux tableaux d'Element* de taille 2*2*/
    string file = "res/test_render.txt";
    State* state = new State();
    state->initialisation(file);
    /*verfication que les instanciations se sont bien deroulees*/
    cout << "Check types..." << endl;   
    CHECK(((Land*)(state->getLands()->getElement(0, 0)))->getType_land() == ROAD);
    CHECK(((Building*)(state->getBuildings()->getElement(1, 0)))->getType_building() == FACTORY);
    CHECK(((Land*)(state->getLands()->getElement(4, 2)))->getType_land() == MOUNTAIN);
    CHECK(((Building*)(state->getBuildings()->getElement(2, 3)))->getType_building() == TOWN);
    
    cout << "All objects are created and correct." << endl;
    
    /*suppression de l'objet State permettant de détruire les pointeurs des tableaux*/
    delete state;
    //cout << "Suppression des pointeurs de TestState terminée." << endl;
}

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
<<<<<<< HEAD
    string file = "res/test_render.txt";
    State* state = new State(file);
    
    CHECK(((Land*)(state->getLands()->getElement(0, 0)))->getType_land() == ROAD);
    CHECK(((Building*)(state->getBuildings()->getElement(1, 0)))->getType_building() == FACTORY);
    CHECK(((Land*)(state->getLands()->getElement(4, 2)))->getType_land() == MOUNTAIN);
    CHECK(((Building*)(state->getBuildings()->getElement(2, 3)))->getType_building() == TOWN);
    /*verfication que les instanciations se sont bien deroulees*/
    cout << "Check types..." << endl;
=======
    State* state = new State(2, 2);
    
    /*instanciation des Elements des tableaux*/
    state->getGrid()->setElement(0, 0, new Land(PLAIN));
    state->getGrid()->setElement(0, 1, new Land(MOUNTAIN));
    state->getGrid()->setElement(1, 0, new Land(BUILDING));
    state->getGrid()->setElement(1, 1, new Land(RIVER));
    
    
    
    state->getCharacters()->setElement(0, 0, new Unit(INFANTRY));
    state->getCharacters()->setElement(0, 1, new Transport(HELICOPTER_T));
    
    /*verification que l'on ne peut pas mettre deux Element* dans la
     meme case d'un tableau sinon risque de reecriture et perte du
     precedent Element* */
    state->getCharacters()->setElement(0, 0, new Unit(MECH));
    
    /*verfication que les instanciations se sont bien deroulees*/
    cout << "Check types..." << endl;
    CHECK(state->getGrid()->getElement(0, 0)->getType_id() == LAND);
    CHECK(state->getGrid()->getElement(0, 0)->isStatic() == true);
    CHECK(state->getGrid()->getElement(0, 1)->getType_id() == LAND);
    CHECK(state->getGrid()->getElement(0, 1)->isStatic() == true);
    CHECK(state->getGrid()->getElement(1, 0)->getType_id() == LAND);
    CHECK(state->getGrid()->getElement(1, 0)->isStatic() == true);
    CHECK(state->getGrid()->getElement(1, 1)->getType_id() == LAND);
    CHECK(state->getGrid()->getElement(1, 1)->isStatic() == true);

    CHECK(state->getCharacters()->getElement(0, 0)->getType_id() == UNIT);
    CHECK(state->getCharacters()->getElement(0, 1)->getType_id() == UNIT);
    
    CHECK(((Unit*)(state->getCharacters()->getElement(0, 0)))->getType_unit() == INFANTRY);
    CHECK(((Transport*)(state->getCharacters()->getElement(0, 1)))->getType_transport() == HELICOPTER_T);
>>>>>>> 6c7cf3bd3aaf1838714150f0f4fd4f0eeb184a42
    
    cout << "All objects are created and correct." << endl;
    
    /*suppression de l'objet State permettant de détruire les pointeurs des tableaux*/
    delete state;
    //cout << "Suppression des pointeurs de TestState terminée." << endl;
}
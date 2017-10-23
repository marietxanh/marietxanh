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
    
    State* state = new State(2, 2);
    state->getGrid()->setElement(0, 0, new Land(PLAIN));
    state->getGrid()->setElement(0, 1, new Land(MOUNTAIN));
    state->getGrid()->setElement(1, 0, new Land(BUILDING));
    state->getGrid()->setElement(1, 1, new Land(RIVER));
    cout << "Check types..." << endl;
    CHECK(state->getGrid()->getElement(0, 0)->getType_id() == LAND);
    CHECK(state->getGrid()->getElement(0, 0)->isStatic() == true);
    CHECK(state->getGrid()->getElement(0, 1)->getType_id() == LAND);
    CHECK(state->getGrid()->getElement(0, 1)->isStatic() == true);
    CHECK(state->getGrid()->getElement(1, 0)->getType_id() == LAND);
    CHECK(state->getGrid()->getElement(1, 0)->isStatic() == true);
    CHECK(state->getGrid()->getElement(1, 1)->getType_id() == LAND);
    CHECK(state->getGrid()->getElement(1, 1)->isStatic() == true);
    
    state->getCharacters()->setElement(0, 0, new Unit(INFANTRY));
    state->getCharacters()->setElement(0, 1, new Transport(HELICOPTER_T));
    
    CHECK(state->getCharacters()->getElement(0, 0)->getType_id() == UNIT);
    CHECK(state->getCharacters()->getElement(0, 1)->getType_id() == UNIT);
    //Unit* unit = (Unit*)(state->getCharacters()->getElement(0, 1));
    //CHECK(unit->getType_unit() == INFANTRY);
    
    CHECK(((Unit*)(state->getCharacters()->getElement(0, 0)))->getType_unit() == INFANTRY);
    CHECK(((Transport*)(state->getCharacters()->getElement(0, 1)))->getType_transport() == HELICOPTER_T);
    cout << "All objects are created and correct." << endl;
    delete state;
}
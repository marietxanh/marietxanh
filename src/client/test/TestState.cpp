/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "TestState.h"

using namespace std;
using namespace status;

void TestState::testState(){
    cout <<  "Test of state in game." << endl;
    
    State state(10, 10);
    unique_ptr<Element> p(new Land(0, 0, BUILDING));
    state.getGrid()->setElement(0, 0, p);
    state.getGrid()->getElement(0, 0)->affiche();
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "../status.h"

int testState(){
    int state = -1;
    
    Unit armee;
    Transport barque;
    Land montagne;
    Building ville;
    
    armee.setTypeUnit(INFANTRY);
    barque.setTypeUnit(TRANSPORT);
    montagne.setTypeLand(MOUNTAIN);
    ville.TypeUnit(BUILDING);
    
    if (armee.getTypeUnit.equals(1) && barque.getTypeUnit.equals(0) && montagne.getTypeLand.equals(2) && ville.getTypeLand.equals(0) )
        state = 0;
    else
        return state;
            
    return state;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include"SelectCharCommand.h"

SelectCharCommand::SelectCharCommand (int c, status::Unit u){
    
}

CommandTypeId const SelectCharCommand::getTypeId (){
    return CommandTypeId(SELECT_CHAR);
}

void SelectCharCommand::execute (status::State& state){
    
    state::ElementTab *tab = state.getCharacters(); // cherche un personnage dans ElementTab
    i = rand ()% tab.size();
    while(tab[i].getElement()!= Units){
        i = rand ()% tab.size();
    }
     // return tab[i].getElement(); //modifier dia?
    
}

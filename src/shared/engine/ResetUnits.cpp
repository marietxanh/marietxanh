/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "ResetUnits.h"

using namespace status;

namespace engine {
    
    ResetUnits::ResetUnits()
    {
        
    }
    CommandTypeID ResetUnits::getTypeID () const
    {
        return RESET;
    }
    void ResetUnits::execute (status::State* state)
    {
        for(int i(0); i < state->getHeight(); i++)
            for(int j(0); j < state->getWidth(); j++)
            {
                if(state->getUnits()->getElement(i, j) != NULL)
                {
                    ((Unit*)(state->getUnits()->getElement(i, j)))->setTurn_attack(false);
                    ((Unit*)(state->getUnits()->getElement(i, j)))->setTurn_move(false);
                }
            }
    }

};
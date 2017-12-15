/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "ResetUnits.h"
#include "ResetUnitsAction.h"

using namespace status;

namespace engine {
    
    ResetUnits::ResetUnits()
    {
        
    }
    CommandTypeID ResetUnits::getTypeID () const
    {
        return RESET;
    }
    void ResetUnits::execute (std::stack<Action*>& actions, status::State* state)
    {
        for(int i(0); i < state->getHeight(); i++)
            for(int j(0); j < state->getWidth(); j++)
            {
                if(state->getUnits()->getElement(i, j) != NULL)
                {
                    ((Unit*)(state->getUnits()->getElement(i, j)))->setTurn_attack(false);
                    ((Unit*)(state->getUnits()->getElement(i, j)))->setTurn_move(false);
                    ResetUnitsAction* reset_unit = NULL;
                    //ResetUnitsAction* reset_unit = new ResetUnitsAction(state->getUnits()->getElement(i, j));
                    actions.push(reset_unit);
                }
            }
    }
    void ResetUnits::serialize (Json::Value& out) const
    {
        out["ResetUnits"];
    }
    ResetUnits* ResetUnits::deserialize (const Json::Value& in)
    {
        return new ResetUnits();
    }
};

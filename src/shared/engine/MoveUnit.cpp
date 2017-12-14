#include "MoveUnit.h"
#include "MoveUnitAction.h"
#include <iostream>

using namespace status;

namespace engine {

	MoveUnit::MoveUnit (int height_start, int width_start, int height_end, int width_end)
	{
		this->height_start = height_start;
		this->width_start = width_start;
		this->height_end = height_end;
		this->width_end = width_end;
	}
	
	MoveUnit::~MoveUnit()
	{
	
	}

	CommandTypeID MoveUnit::getTypeID () const
	{
		return MOVE;
	}

	void MoveUnit::execute (std::stack<Action*>& actions, status::State* state)
	{
            MoveUnitAction* move_unit = NULL;
		if(height_start != height_end || width_start != width_end)
		{
                    if(((Unit*)(state->getUnits()->getElement(height_start, width_start)))->getTurn_move() == false)
                    {
			std::cout << "Move units from (" << height_start << ", " << width_start << ") to (" << height_end << ", " << width_end << ")\n" << std::endl;
			((Unit*)(state->getUnits()->getElement(height_start, width_start)))->setTurn_move(true);
                        if(((Unit*)(state->getUnits()->getElement(height_start, width_start)))->getDouble_action() == false)
                        {
                            ((Unit*)(state->getUnits()->getElement(height_start, width_start)))->setTurn_attack(true);
                        }
                        if(state->getUnits()->setElement(height_end, width_end, state->getUnits()->getElement(height_start, width_start)))
                            state->getUnits()->setElement(height_start, width_start, NULL);
                        //move_unit->setHeight_start(height_start); move_unit->setWidth_start(width_start);
                        //move_unit->setHeight_end(height_end); move_unit->setWidth_end(width_end);
                        //move_unit->setElement(state->getUnits()->getElement(height_end, width_end));
                        actions.push(move_unit);
                    }
		}
		else std::cout << "Unit already use this place\n" << std::endl;
	}
        void MoveUnit::serialize (Json::Value& out) const
        {
       		out["MoveUnit"]["height_start"] = this->height_start;
		   	out["MoveUnit"]["width_start"] = this->width_start;
		   	out["MoveUnit"]["height_end"] = this->height_end;
			out["MoveUnit"]["width_end"] = this->width_end;
        }
        MoveUnit* MoveUnit::deserialize (const Json::Value& in)
        {
            MoveUnit* move_unit = new MoveUnit(in["MoveUnit"]["height_start"].asInt(), in["MoveUnit"]["width_start"].asInt(),
                    in["MoveUnit"]["height_end"].asInt(), in["MoveUnit"]["width_end"].asInt());
            return move_unit;
        }
	
};

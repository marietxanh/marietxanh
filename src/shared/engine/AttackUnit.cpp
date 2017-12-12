#include "AttackUnit.h"
#include <iostream>

using namespace engine;
using namespace status;

namespace engine {

	AttackUnit::AttackUnit(int height_shooter, int width_shooter, int height_target, int width_target)
	{
		this->height_shooter = height_shooter;
		this->width_shooter = width_shooter;
		this->height_target = height_target;
		this->width_target = width_target;
	}

	AttackUnit::~AttackUnit()
	{
	
	}
	
	CommandTypeID AttackUnit::getTypeID () const
	{
		return ATTACK;
	}

	void AttackUnit::execute (std::stack<Action*>& actions, status::State* state)
	{
            if(state->getUnits()->getElement(height_target, width_target) != NULL)
            {
                if(((Unit*)(state->getUnits()->getElement(height_shooter, width_shooter)))->getTeam() != ((Unit*)(state->getUnits()->getElement(height_target, width_target)))->getTeam())
                {
                    if(((Unit*)(state->getUnits()->getElement(height_shooter, width_shooter)))->getTurn_attack() == false)
                    {
                        std::cout << "execute attack" << std::endl;
                        int attack = ((Unit*)(state->getUnits()->getElement(height_shooter, width_shooter)))->getAttack();
                        ((Unit*)(state->getUnits()->getElement(height_shooter, width_shooter)))->setTurn_attack(true);
                        ((Unit*)(state->getUnits()->getElement(height_shooter, width_shooter)))->setTurn_move(true);
                        ((Unit*)(state->getUnits()->getElement(height_target, width_target)))->setHealth(-attack);
                        std::cout << "Unit from (" << height_shooter << ", " << width_shooter << ") attack unit in (" << height_target << ", " << width_target << ")" << std::endl;
                        std::cout << "Health of attacked unit : " << ((Unit*)(state->getUnits()->getElement(height_target, width_target)))->getHealth() << std::endl;
                        if(((Unit*)(state->getUnits()->getElement(height_target, width_target)))->getHealth() <= 0)
                        {
                            delete state->getUnits()->getElement(height_target, width_target);
                            state->getUnits()->setElement(height_target, width_target, NULL);
                            std::cout << "Unit in (" << height_target << ", " << width_target <<") destroyed" << std::endl;
                        }
                    }
                }
            }
            else std::cout << "No target in (" << height_target << ", " << width_target << ")\n" << std::endl;
	}
        void AttackUnit::serialize (Json::Value& out) const
        {
		   out["AttackUnit"]["height_shooter"] = this->height_shooter;
		   out["AttackUnit"]["width_shooter"] = this->width_shooter;
		   out["AttackUnit"]["height_target"] = this->height_target;
		   out["AttackUnit"]["width_target"] = this->width_target;
        }
        AttackUnit* AttackUnit::deserialize (const Json::Value& in)
        {
            AttackUnit* attack_unit = new AttackUnit(in["AttackUnit"]["height_shooter"], in["AttackUnit"]["width_shooter"], in["AttackUnit"]["height_target"], in["AttackUnit"]["widht_target"]);
            return attack_unit;
        }

};

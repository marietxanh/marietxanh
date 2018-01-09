#include "AttackUnit.h"
#include <iostream>
#include <random>

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
                        int attack;
                        if(((Unit*)(state->getUnits()->getElement(height_shooter, width_shooter)))->getType_unit() != status::TRANSPORT)
                            attack = ((Unit*)(state->getUnits()->getElement(height_shooter, width_shooter)))->getDamage_on_unit(((Unit*)(state->getUnits()->getElement(height_shooter, width_shooter)))->getType_unit());
                        else
                            attack = ((Transport*)(state->getUnits()->getElement(height_shooter, width_shooter)))->getDamage_on_transport(((Transport*)(state->getUnits()->getElement(height_shooter, width_shooter)))->getType_transport());
                        int health_shooter = ((Unit*)(state->getUnits()->getElement(height_shooter, width_shooter)))->getHealth();
                        int defense = ((Land*)(state->getLands()->getElement(height_target, width_target)))->getDefense();
                        int health_target = ((Unit*)(state->getUnits()->getElement(height_target, width_target)))->getHealth();
                        ((Unit*)(state->getUnits()->getElement(height_shooter, width_shooter)))->setTurn_attack(true);
                        ((Unit*)(state->getUnits()->getElement(height_shooter, width_shooter)))->setTurn_move(true);
                        if(attack > 0)
                        {
                            int damage = damage_formula(attack, health_shooter, defense, health_target);
                            ((Unit*)(state->getUnits()->getElement(height_target, width_target)))->setHealth(-damage);
                            std::cout << "Unit from (" << height_shooter << ", " << width_shooter << ") attack unit in (" << height_target << ", " << width_target << ")" << std::endl;
                            std::cout << "Health of attacked unit : " << ((Unit*)(state->getUnits()->getElement(height_target, width_target)))->getHealth() << std::endl;
                        }
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
            out["type_command"] = "AttackUnit";
            out["height_shooter"] = this->height_shooter;
            out["width_shooter"] = this->width_shooter;
            out["height_target"] = this->height_target;
            out["width_target"] = this->width_target;
        }
        AttackUnit* AttackUnit::deserialize (const Json::Value& in)
        {
            AttackUnit* attack_unit = new AttackUnit(in["height_shooter"].asInt(), in["width_shooter"].asInt()
                    , in["height_target"].asInt(), in["width_target"].asInt());
            return attack_unit;
        }
        
        int AttackUnit::damage_formula(int attack, int health_shooter, int defense, int health_target)
        {
            std::random_device seed;
            std::mt19937 gen(seed());
            std::uniform_int_distribution<int> dis(0, 9);
            int damage = (attack + dis(gen)) * (health_shooter / 10) * ((100 - (defense * health_target)) / 100);
            if(damage > 120) damage = 120;
            damage /= 10;
            return damage;
        }

};

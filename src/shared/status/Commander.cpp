#include "../status/Commander.h"
namespace status {

    Commander::Commander(int bonusMvmt, int bonusRange, int bonusAtk):bonusMvmt(bonusMvmt), bonusRange(bonusRange), bonusAtk(bonusAtk)
    {

    }

    Commander::~Commander()
    {

    }

    TEAM Commander::getTeam () const
    {
        return this->team;
    }
    
    void Commander::setTeam (TEAM team)
    {
        this->team = team;
    }
}
#include "../status/Commander.h"
using namespace status;
Commander::Commander(int bonusMvmt, int bonusRange, int bonusAtk):bonusMvmt(bonusMvmt), bonusRange(bonusRange), bonusAtk(bonusAtk)
{

}

Commander::~Commander()
{

}

TypeCommander Commander::getType_commander() const
{
        return type_commander;
}

void Commander::setType_commander(TypeCommander commander)
{
        this->type_commander = commander;
}

#include "../status/Commander.h"

Commander::Commander(int bonusMvmt, int bonusRange, int bonusAtk):this->bonusMvmt(bonusMvmt), this->bonusRange(bonusRange), this->bonusAtk(bonusAtk)
{

}

Commander::~Commander()
{

}

TypeCommander Commander::getTypeCommander()
{
        return type_commander;
}

void Commander::setTypeCommander(TypeCommander type)
{
        this->type_commander = type;
}

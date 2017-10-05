#include "../status/State.h"
using namespace status;

State::State()
{
        grid = new ElementTab(0, 1, LAND);
        units = new ElementTab(0, 1, UNIT);
}

State::~State()
{
        delete grid;
        delete units;
}

ElementTab* State::getGrid()
{
        return grid;
}

ElementTab* State::getCharacters()
{
        return units;
}

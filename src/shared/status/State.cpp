#include "../status/State.h"
using namespace status;

State::State(size_t width, size_t height)
{
        grid = new ElementTab(width, height, LAND);
        units = new ElementTab(width, height, UNIT);
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

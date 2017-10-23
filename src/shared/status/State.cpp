#include "../status/State.h"
using namespace status;
using namespace std;

State::State(int width, int height)
{
        grid = new ElementTab(width, height, LAND);
        units = new ElementTab(width, height, UNIT);
}

State::~State()
{

}

ElementTab* State::getGrid()
{
        return grid;
}

ElementTab* State::getCharacters()
{
        return units;
}

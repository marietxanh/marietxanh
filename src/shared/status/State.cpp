#include "../status/State.h"
using namespace status;
using namespace std;

State::State(int width, int height)
{
        grid.reset(new ElementTab(width, height, LAND));
        units.reset(new ElementTab(width, height, UNIT));
}

State::~State()
{

}

unique_ptr<ElementTab>& State::getGrid()
{
        return grid;
}

unique_ptr<ElementTab>& State::getCharacters()
{
        return units;
}

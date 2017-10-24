#include "../status/State.h"
#include <iostream>
using namespace status;
using namespace std;

State::State(int width, int height)
{
        grid = new ElementTab(width, height, LAND);
        units = new ElementTab(width, height, UNIT);
}

State::~State()
{
    delete grid;
    delete units;
    //cout << "Suppression des tableaux d'unités et terrains terminée." << endl;
}

ElementTab* State::getGrid()
{
        return grid;
}

ElementTab* State::getCharacters()
{
        return units;
}

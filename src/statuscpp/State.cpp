#include "../status/State.h"

State::State(){
        grid = new ElementTab(0, 1);
        units = new ElementTab(0, 1);
}

State::~State(){
        delete grid;
        delete units;
}

ElementTab* State::getGrid()
{
        return grid;
}

ElementTab* State::getCharacter()
{
        return character;
}

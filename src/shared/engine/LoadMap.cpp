#include "LoadMap.h"
#include <iostream>

using namespace engine;
using namespace status;

LoadMap::LoadMap (const char* file_name)
{
	this->file_name = file_name;
}
CommandTypeID LoadMap::getTypeID () const
{
	return LOAD;
}
void LoadMap::execute (status::State& state)
{
	state.initialization(file_name);
	std::cout << "Map loaded" << endl;
}

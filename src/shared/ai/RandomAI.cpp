#include "RandomAI.h"
#include <iostream>
#include <time>

using namespace engine;
using namespace ai;


RandomAI::RandomAI (int randomSeed)
{
	this->randgen = rand()%randomSeed;
}

void RandomAI::run (engine::Engine& engine)
{
	
}

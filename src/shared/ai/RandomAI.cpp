#include "RandomAI.h"
#include <iostream>

using namespace engine;

using namespace ai{

RandomAI::RandomAI (int randomSeed)
{

	randgen(randomSeed);
}

void RandomAI::run (engine::Engine& engine)
{	
	std::vector<engine::Command*> list;

	listCommands(list,engine.getState()); 
	engine.addCommand(list[randgen]);
	engine.update();
	
}

}

#include "RandomAI.h"
#include <iostream>
#include <time.h>

using namespace engine;

using namespace ai{

RandomAI::RandomAI (int randomSeed)
{
	this->randgen.seed(randomSeed);
}

void RandomAI::run (engine::Engine& engine)
{	
	std::vector<engine::Command*> list;
	
	// ElementTab* tab = engine.getState().getUnits();
	listCommands(list,engine.getState()); 
	engine.addCommand(list[randgen]);
	engine.update();
	
}

}

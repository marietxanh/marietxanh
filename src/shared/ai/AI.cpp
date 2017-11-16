#include "AI.h"
#include <iostream>

using namespace engine;
using namespace status;


using namespace ai{

void AI::listCommands (std::vector<engine::Command*>& list, const status::State& state)

{
	engine.setState(state);
	list.push_back(engine.currentCommands);
}

}


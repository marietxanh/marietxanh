#include "AI.h"
#include <iostream>

using namespace engine;
using namespace status;

void AI::listCommands (std::vector<engine::Command*>& list, const status::State& state)
{
	engine.setState(state);
	list.add(engine.currentCommands);
}


#include "AI.h"
#include <iostream>

using namespace engine;
using namespace status;

<<<<<<< HEAD
namespace ai {

void AI::listCommands (std::vector<std::unique_ptr<engine::Command>>& list, const status::State& state)
=======
using namespace ai{

void AI::listCommands (std::vector<engine::Command*>& list, const status::State& state)
>>>>>>> b41c5e0710cc917897d8cdbf98b1590c232a1197
{
	engine.setState(state);
	list.add(engine.currentCommands);
}

}
<<<<<<< HEAD



=======
>>>>>>> b41c5e0710cc917897d8cdbf98b1590c232a1197

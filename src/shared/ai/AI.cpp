#include "AI.h"
#include <iostream>

using namespace engine;

namespace ai{

	void AI::setlist(std::vector<Command*> listarg)
	{
		list.resize(listarg.size());
		list = listarg;

	}
	
	Command* AI::getCommand (int randgen)
	{	
		return list[randgen];
	}

};


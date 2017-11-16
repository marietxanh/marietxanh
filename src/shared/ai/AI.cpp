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
		if(ranfgen <= list.size())
		{
			return list[randgen];
		}
		else 
		{
			std::cout << "erreur randgen" << std::endl;
        		exit(EXIT_FAILURE);
		}
	}

};


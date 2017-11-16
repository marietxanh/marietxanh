#include "RandomAI.h"
#include <iostream>
#include <random>

using namespace engine;

namespace ai{

	RandomAI::RandomAI (int randomSeed)
	{
		mt19937::result_type seed = time(0);
		randgen = std::bind(std::uniform_int_distribution<int>(0,randomSeed - 1),
                           mt19937(seed));
	}

	void RandomAI::run (engine::Engine* engine)
	{
		/* on prend une commande random dans la liste et on 			l'applique au tableau d'elements visé */
		int height = engine->getState()->getUnits()->getTab().size();
		int width = engine->getState()->getUnits()->getTab()[0].size();
		for(int i(0); i < height; i++)
		{
			for(int j(0); j < width; j++)
			{
				if(engine->getState()->getUnits()->getElement(i,j)!=NULL)
				{
					engine->addCommand(this->getCommand(randgen));
					engine->update();
					std::cout << "Unit has moved" << std::endl;
				}
				else 
				{
					std::cout << "No Unit on the ElementTab " << std::endl;
        				exit(EXIT_FAILURE);
				}
			}
		}
	
	}

	void RandomAI::set_randgen (int randomSeed)
	{
		randgen.seed(randomSeed);
	}

};

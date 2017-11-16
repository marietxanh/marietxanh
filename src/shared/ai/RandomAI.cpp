#include "RandomAI.h"
#include <iostream>

using namespace engine;

namespace ai{

	RandomAI::RandomAI (int randomSeed)
	{
		randgen.seed(randomSeed);
	}

	void RandomAI::run (engine::Engine* engine)
	{
		/* on prend une commande random dans la liste et on 			l'applique au tableau d'elements visé */
		int width = engine->getState()->getUnits()->getElement().size();
		int height = engine->getState()->getUnits()->getElement()[0].size();
		for(int i(0); i < height; i++)
		{
			for(int j(0); j < width; j++)
			{
				if(engine->getState()->getUnits()->getElement(i,j)!=NULL)
				{
					engine->addCommand(list[randgen]);
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

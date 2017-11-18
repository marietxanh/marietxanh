#include "RandomAI.h"
#include <iostream>
#include <random>

using namespace engine;

namespace ai{

	RandomAI::RandomAI ()
	{
	
	}

	void RandomAI::run (engine::Engine* engine)
	{
		/* on prend une commande random dans la liste et on 			l'applique au tableau d'elements visé */
		int height = engine->getState()->getHeight();
		int width = engine->getState()->getWidth();
		for(int i(0); i < height; i++)
		{
			for(int j(0); j < width; j++)
			{
				if(engine->getState()->getUnits()->getElement(i,j) != NULL)
				{
					engine->addCommand(this->getCommand(i, j, height, width));
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
};

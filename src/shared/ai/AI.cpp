#include "../engine.h"
#include "AI.h"
#include <iostream>
#include <unistd.h>
#include <time.h>

using namespace engine;

namespace ai {
	
	Command* AI::getCommand (int i, int j, int height, int width) const
	{	
		int size = 0;
		int random = 0;
		int vertical = 0;
		int horizontal = 0;
		size = list.size();
		random = rand();
		std::string choice = list[random % size];
		if(choice == "move")
		{
			do
			{
				vertical = rand() % 3 - 1;
				sleep(0.5);
				horizontal= rand() % 3 - 1;
				sleep(0.5);
			}while( ((vertical + i) >= height || (vertical + i) < 0) || ((horizontal + j) >= width || (horizontal + j) < 0) );
			
			MoveUnit *new_move = new MoveUnit(i, j, i + vertical, j + horizontal);
			return new_move;
		}
		else if(choice == "attack")
		{
			int target;
			do
			{
				target = rand() % 2;
				switch (target)
				{
					case 0:
						vertical = rand() % 3 - 1;
						sleep(0.5);
						break;
					case 1:
						horizontal = rand() % 3 - 1;
						sleep(0.5);
						break;
					default:
						sleep(0.5);
						break;
				}
			}while( ((vertical + i) >= height || (vertical + i) < 0) || ((horizontal + j) >= width || (horizontal + j) < 0) );
			
			AttackUnit *new_attack = new AttackUnit(i, j, i + vertical, j + horizontal);
			return new_attack;
		}
		else
		{
			return NULL;
		}
	}
	
	void AI::addCommand(std::string& command)
	{
		list.push_back(command);
	}

};


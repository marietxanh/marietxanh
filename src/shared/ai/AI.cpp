#include "../engine.h"
#include "AI.h"
#include <iostream>
#include <unistd.h>
#include <random>
//#include <time.h>

using namespace engine;

namespace ai {
	
	Command* AI::getCommand (int i, int j, int height, int width) const
	{	
		int size = 0;
		//int random = 0;
		int vertical = 0;
		int horizontal = 0;
		size = list.size();
		//random = rand();
                std::random_device seed;
                std::mt19937 gen(seed());
                std::uniform_int_distribution<> dis(0,size-1);
                std::uniform_int_distribution<int> rand(-1,1);
		//std::string choice = list[random % size];
                std::string choice = list[dis(gen)];
		if(choice == "move")
		{
			do
			{
				//vertical = rand() % 3 - 1; 
                                vertical = rand(gen);
                                std::cout << "vertical=" << vertical << std::endl;
				sleep(2);
				//horizontal= rand() % 3 - 1;
                                horizontal= rand(gen);
                                std::cout << "horizontal=" << horizontal << std::endl;
				sleep(2);
			}while( ((vertical + i) >= height || (vertical + i) < 0) || ((horizontal + j) >= width || (horizontal + j) < 0) );
			
			MoveUnit *new_move = new MoveUnit(i, j, i + vertical, j + horizontal);
			return new_move;
		}
		else if(choice == "attack")
		{
			int target;
			do
			{
				//target = rand() % 2;
                                std::uniform_int_distribution<> random(0,1);
                                target = random(gen);
                                std::cout << "target=" << target << std::endl;
				switch (target)
				{
					case 0:
						//vertical = rand() % 3 - 1;
                                                vertical = rand(gen);
                                                std::cout << "vertical=" << vertical << std::endl;
						sleep(2);
						break;
					case 1:
						//horizontal = rand() % 3 - 1;
                                                horizontal = rand(gen);
                                                std::cout << "horizontal=" << horizontal << std::endl;
						sleep(2);
						break;
					default:
						sleep(2);
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


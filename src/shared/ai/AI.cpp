#include "../engine.h"
#include "AI.h"
#include <iostream>
#include <unistd.h>
#include <random>
//#include <time.h>

using namespace engine;
using namespace std;

namespace ai {
	
	Command* AI::getCommand (int i, int j, int height, int width) const
	{	
		int size = 0;
		int vertical = 0;
		int horizontal = 0;
		size = list.size();
                std::random_device seed;
                std::mt19937 gen(seed());
                std::uniform_int_distribution<> dis(0,size-1);
                std::uniform_int_distribution<int> rand(-1,1);
                std::string choice = list[dis(gen)];
		if(choice == "move")
		{
			do
			{
                                vertical = rand(gen);
                                horizontal= rand(gen);
			}while( ((vertical + i) >= height || (vertical + i) < 0) || ((horizontal + j) >= width || (horizontal + j) < 0) );
			MoveUnit *new_move = new MoveUnit(i, j, i + vertical, j + horizontal);
			return new_move;
		}
		else if(choice == "attack")
		{
			int target;
			do
			{
                                std::uniform_int_distribution<> random(0,1);
                                target = random(gen);
				switch (target)
				{
					case 0:
                                                while((vertical = rand(gen)) == 0);
						break;
					case 1:
                                                while((horizontal = rand(gen)) == 0);
						break;
					default:
						break;
				}
			}while( ((vertical + i) >= height || (vertical + i) < 0) || ((horizontal + j) >= width || (horizontal + j) < 0) );
			
                        cout << "Shooter in : (" << i << ", " << j << ")\t";
                        cout << "Target in : (" << vertical + i << ", " << horizontal + j << ")" << endl;
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


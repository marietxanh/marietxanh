#include "../status.h"
#include <iostream>
#include <unistd.h>
#include <limits>
#include "PathMap.h"

using namespace status;

namespace ai {

    PathMap::PathMap ()
    {

    }

    int  PathMap::getWeight (const Point& p) const
    {
            return p.getWeight();
    }

    void PathMap::setWeight (const Point& p)
    {
            this->weights.push_back(p.getWeight());
    }

    const std::vector<int>& PathMap::getWeights () const
    {
            return this->weights;
    }
    
    int PathMap::getMapWeight (int i, int j) const
    {
        return this->map[i][j];
    }

    void PathMap::setMapDistances (status::ElementTab* grid, int height, int width, status::TEAM team)
    {
        //*
        std::cout << "resize... ";
        
        this->map.resize(height);
        
        std::cout << "OK" << std::endl;
        for(int i(0); i < height; i++)
        {
            this->map[i].resize(width);
            for(int j(0); j < width; j++)
            {
                if(grid->getElement(i, j) != NULL)
                {
                    if(grid->getElement(i, j)->getType_id() == LAND)
                    {
                        if(((Building*)(grid->getElement(i, j)))->getTeam() == team)
                        {
                            this->queue.push(Point{i, j, 0});
                            map[i][j] = 0;
                        }
                        else map[i][j] = 99;
                    }
                    else if(grid->getElement(i ,j)->getType_id() == UNIT)
                    {
                        if(((Unit*)(grid->getElement(i, j)))->getTeam() == team)
                        {
                            this->queue.push(Point{i, j, 0});
                            map[i][j] = 0;
                        }
                        else map[i][j] = 99;
                    }
                }
                else map[i][j] = 99;
            }
        }
        std::cout << "begin heuristic search" << std::endl;
        int k = 0;
        while(!this->queue.empty())
        {
            auto p = this->queue.top(); this->queue.pop();
            for(Direction d = NORTH; d <= WEST; d = static_cast<Direction>(d+1))
            {
                auto pp = p.transform(d);
                if(pp.getX() >= 0 && pp.getX() < height && pp.getY() >= 0 && pp.getY() < width)
                {
                    if(this->getWeight(pp) < map[pp.getX()][pp.getY()])
                    {
                        this->queue.push(pp);
                        map[pp.getX()][pp.getY()] = pp.getWeight();
                        k++;
                    }
                }
            }
        }
        std::cout << "heuristic search turns : " << k << std::endl;
        //*
        for(int i(0); i < height; i++)
        {
            for(int j(0); j < width; j++)
            {
                std::cout << map[i][j] << "\t";
            }
            std::cout << std::endl;
        }
        //*/
    }
};

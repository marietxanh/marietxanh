
#include "HeuristicAI.h"
#include "engine/AttackUnit.h"
#include "engine/MoveUnit.h"
#include <unistd.h>
#include <iostream>

namespace ai {

    HeuristicAI::HeuristicAI ()
    {
        this->units_map.resize(2);
        this->buildings_map.resize(2);
    }

    const PathMap& HeuristicAI::getAdvUnitsMap (status::TEAM team) const
    {
        if (team == status::ORANGE) return this->units_map[0];
        else return this->units_map[1];
    }

    const PathMap& HeuristicAI::getBuildingMap (status::TEAM team) const
    {
        if(team == status::ORANGE) return this->buildings_map[0];
        else return this->buildings_map[1];
    }

    void HeuristicAI::run (engine::Engine* engine)
    {
        int height = engine->getState()->getHeight();
        int width = engine->getState()->getWidth();
        /* on prend la même fonction que dans random AI */
        
        for(int t(0); t < 2; t++)
        {
            for(int l = 0; l < 2; l++)
            {
                std::cout << "maps for team " << l << "\nunits" << std::endl;
                this->units_map[l].setMapDistances(engine->getState()->getUnits(), height, width, ((status::TEAM)(l + 1)));
                std::cout << "buildings" << std::endl;
                this->buildings_map[l].setMapDistances(engine->getState()->getBuildings(), height, width, ((status::TEAM)(l + 1)));
            }
            for(int i(0); i < height; i++)
            {
                for(int j(0); j < width; j++)
                {
                    if(engine->getState()->getUnits()->getElement(i,j) != NULL)
                    {
                        int range = ((status::Unit*)(engine->getState()->getUnits()->getElement(i, j)))->getRange_shoot();
                        for(int k(0); k < range; k++)
                        {
                            std::priority_queue<Point,std::vector<Point>,PcompW> area;
                            if(i > 0) area.push(Point{i - 1, j , units_map[1 - t].getMapWeight(i - 1, j)});
                            if(i < height - 1) area.push(Point{i + 1, j, units_map[1 - t].getMapWeight(i + 1, j)});
                            if(j > 0) area.push(Point{i, j - 1, units_map[1 - t].getMapWeight(i, j - 1)});
                            if(j < width - 1) area.push(Point{i, j + 1, units_map[1- t].getMapWeight(i, j + 1)});
                            auto p = area.top();
                            area.pop();
                            while(!area.empty())
                            {
                                p = area.top(); area.pop();
                            }
                            if(p.getWeight() > 0) engine->addCommand(new engine::MoveUnit(i, j, p.getX(), p.getY()));
                            else engine->addCommand(new engine::AttackUnit(i, j, p.getX(), p.getY()));
                            engine->update();   
                        }
                    }
                }
            }
        }
    }

};


#include "HeuristicAI.h"
#include <unistd.h>
#include <iostream>

namespace ai {

    HeuristicAI::HeuristicAI ()
    {

    }

    const PathMap&  HeuristicAI::getAdvUnitsMap () const
    {
            return this->adv_units_map;
    }

    const PathMap&  HeuristicAI::getBuildingMap () const
    {
            return this->building_map;
    }

    void HeuristicAI::run (engine::Engine* engine)
    {
        int height = engine->getState()->getHeight();
        int width = engine->getState()->getWidth();
        /* on prend la même fonction que dans random AI */
        std::cout << "units : \n";
        this->adv_units_map.setMapDistances(engine->getState()->getUnits(), height, width);
        std::cout << "buildings : \n";
        this->building_map.setMapDistances(engine->getState()->getBuildings(), height, width);

        /*
        for(int i(0); i < height; i++)
        {
                for(int j(0); j < width; j++)
                {
                        if(engine->getState()->getUnits()->getElement(i,j) != NULL)
                        {
                                //engine->addCommand(this->getCommand(i, j, height, width));
                                //engine->update();
                        }
                }
        }
        //*/
    }

};

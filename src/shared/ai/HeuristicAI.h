// Generated by dia2code
#ifndef AI__HEURISTICAI__H
#define AI__HEURISTICAI__H

#include <vector>

namespace ai {
  class PathMap;
};
namespace engine {
  class Engine;
};
namespace ai {
  class AI;
}

#include "PathMap.h"
#include "AI.h"

namespace ai {

  /// class HeuristicAI - 
  class HeuristicAI : public ai::AI {
    // Associations
    // Attributes
  private:
    std::vector<PathMap> units_map;
    std::vector<PathMap> buildings_map;
    // Operations
  public:
    HeuristicAI ();
    const PathMap& getAdvUnitsMap (status::TEAM team) const;
    const PathMap& getBuildingMap (status::TEAM team) const;
    void run (engine::Engine* engine);
    // Setters and Getters
  };

};

#endif

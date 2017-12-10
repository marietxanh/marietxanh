// Generated by dia2code
#ifndef AI__DEEPAI__H
#define AI__DEEPAI__H

#include <vector>
#include "status.h"

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

  /// class DeepAI - 
  class DeepAI : public ai::AI {
    // Associations
    // Attributes
  private:
    std::vector<PathMap> buildings_map;
    std::vector<PathMap> units_map;
    PathMap qg_map;
  protected:
    int maxDepth     = 4;
    // Operations
  public:
    DeepAI (const status::State& state);
    int minmax_rec_max (engine::Engine* engine, Direction& bestdir, int depth);
    minmax_rec_min (engine::Engine* engine, Direction& bestdir, int depth);
    void run (engine::Engine* engine);
    // Setters and Getters
    int getMaxDepth() const;
    void setMaxDepth(int maxDepth);
  };

};

#endif

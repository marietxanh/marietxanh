// Generated by dia2code
#ifndef AI__PATHMAP__H
#define AI__PATHMAP__H

#include <vector>
#include <queue>

namespace ai {
  class Point;
};
namespace status {
  class ElementTab;
};
namespace ai {
  class PcompW;
}

#include "status/ElementTab.h"
#include "PcompW.h"
#include "Point.h"

namespace ai {

  /// class PathMap - 
  class PathMap {
    // Associations
    // Attributes
  private:
    int width     = 0;
    int height     = 0;
    std::vector<int> weights;
    std::priority_queue<Point,std::vector<Point>,PcompW> queue;
    // Operations
  public:
    PathMap ();
    int getWeight (const Point& p) const;
    void setWeight (const Point& p);
    const std::vector<int>& getWeights () const;
    void init (status::ElementTab* grid);
    // Setters and Getters
  };

};

#endif

// Generated by dia2code
#ifndef AI__POINT__H
#define AI__POINT__H


namespace ai {
  class Point;
}

#include "Direction.h"

namespace ai {

  /// class Point - 
  class Point {
    // Associations
    // Attributes
  protected:
    int x;
    int y;
    int weight;
    // Operations
  public:
    Point (int x, int y, int w);
    Point transform (Direction d);
    // Setters and Getters
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    int getWeight() const;
    void setWeight(int weight);
  };

};

#endif
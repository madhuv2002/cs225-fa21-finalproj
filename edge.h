#pragma once

#include <string>
#include "stoppoint.h"
using namespace std;

class Edge {
  public:
    /**
     * Edge constructor.
     * @param begin - starting point
     * @param final - ending point
     */
    Edge(StopPoint start, StopPoint end, double weight);

    /**
     * Default constructor.
     */
    Edge();

    void setStartPoint(StopPoint t);
    StopPoint getStartPoint();

    void setEndPoint(StopPoint t);
    StopPoint getEndPoint();

    void setWeight(double t);
    double getWeight();
    bool operator==(const Edge& rhs) const;

private:
    string name_; 
    StopPoint start_;
    StopPoint end_; 
    double weight_;
};
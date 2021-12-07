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
    Edge(string name, StopPoint start, StopPoint end, double weight, string route);

    /**
     * Default constructor.
     */
    Edge();

    void setName(string name);
    string getName();

    void setStartPoint(StopPoint t);
    StopPoint getStartPoint();

    void setEndPoint(StopPoint t);
    StopPoint getEndPoint();

    void setWeight(double t);
    double getWeight();
    bool operator==(const Edge& rhs) const;

    void setRoute(string route);
    string getRoute();

    ~Edge() {}

private:
    string name_; 
    StopPoint start_;
    StopPoint end_; 
    double weight_;
    string route_;
};
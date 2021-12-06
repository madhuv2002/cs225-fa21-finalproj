#pragma once

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "stoppoint.h"
#include "edge.h"
#include "routemap.h"
#include "cs225/PNG.h"
using namespace cs225;
using namespace std;

class Visualizer {
    public:
    // distance, set location for all the points, draw, map of node to points, 
    // function to calculate weight of node 
    cs225::PNG draw();
    void setLocation(StopPoint p);
    double calculateWeight(StopPoint p);

    private:
    map<StopPoint, std::pair<double, double>()> pointsMap;

};

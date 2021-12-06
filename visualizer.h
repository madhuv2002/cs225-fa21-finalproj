#pragma once

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "stoppoint.h"
#include "edge.h"
#include "routemap.h"
#include "cs225/PNG.h"
#include <math.h>

using namespace cs225;
using namespace std;

class Visualizer {
    public:
    // distance, set location for all the points, draw, map of node to points, 
    // function to calculate weight of node 
    cs225::PNG draw();
    void setLocation(RouteMap map);
    double calculateWeight(StopPoint p);

    private:
    map<StopPoint, std::pair<double, double>()> pointsMap;
    std::pair<double, double> origin;
    std::pair<double, double> endpoint;

    std::pair<double, double> scaleFactor;
    std::pair<double, double> displacement;
};

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
#include <cmath>

using namespace cs225;
using namespace std;

class Visualizer {
    public:
    // distance, set location for all the points, draw, map of node to points, 
    // function to calculate weight of node 
    cs225::PNG* draw(RouteMap map) const;
    void findLocation(RouteMap map);
    double calculateWeight(StopPoint point, RouteMap map);
    void drawEdges(std::pair<StopPoint, std::pair<double, double>> pair, RouteMap map, cs225::PNG* png) const;
   

    map<StopPoint, std::pair<double, double>> pointsMap;
    std::pair<double, double> origin;
    std::pair<double, double> endpoint;

    std::pair<double, double> scaleFactor;
    std::pair<double, double> displacement;
};

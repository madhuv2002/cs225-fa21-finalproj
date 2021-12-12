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
    cs225::PNG* draw();
    void findLocation(RouteMap map);
    void findOrigin();
    void calculateMinDistance();
    double calculateWeight(StopPoint point);
    void drawEdges(pair<StopPoint, pair<double, double>> pair);
    void drawLine(size_t startX, size_t endX, size_t startY, size_t endY, double slope, double b, char parse);

    RouteMap routeMap;
    map<string, pair<StopPoint, vector<Edge>>> vertexMap;
    map<StopPoint, pair<double, double>> pointsMap;

    cs225::PNG* png;

    std::pair<double, double> origin;
    std::pair<double, double> endpoint;

    std::pair<double, double> scaleFactor;
    std::pair<double, double> displacement;

    double minLat;
    double minLon;
    double maxLat;
    double maxLon;
};

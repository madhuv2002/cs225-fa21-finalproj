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
        cs225::PNG* draw();
        void findLocation(RouteMap map);
        void findOrigin();
        void calculateMinDistance();
        void drawEdges(pair<StopPoint, pair<double, double>> pair);
        void drawLine(size_t startX, size_t endX, size_t startY, size_t endY, double slope, double b, char parse);

        RouteMap routeMap;
        map<string, pair<StopPoint, vector<Edge>>> vertexMap;
        map<StopPoint, pair<double, double>> pointsMap;

        PNG* png;

        pair<double, double> origin;
        pair<double, double> endpoint;

        pair<double, double> scaleFactor;
        pair<double, double> displacement;

        double minLat = INT_MAX;
        double minLon = INT_MAX; 

        double maxLat = INT_MIN;
        double maxLon = INT_MIN;
};

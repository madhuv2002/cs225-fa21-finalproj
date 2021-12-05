#pragma once 
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "stoppoint.h"
#include "stop.h"
#include "edge.h"

class RouteMap {
    public:
        map<std::string, StopPoint> vertexMap;
        void loadNode(std::string fileName);
        map<std::string, Edge> edgeMap;
         //std::vector<std::string> tokenize(string s, string del = " ");
        void loadEdges();
        void loadEdges(std::string fileName);
        double calculateWeights(std::string departureTime, std::string arrivalTime);
};
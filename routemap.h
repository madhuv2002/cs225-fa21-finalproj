#pragma once 

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>

#include "stoppoint.h"
#include "edge.h"

using namespace std;

class RouteMap {
    public:
        void loadNode(string fileName);
        void loadEdges();
        map<string, pair<StopPoint, vector<Edge>>> getVertexMap();
        map<string, Edge> getEdgeMap();

    private:
        map<string, pair<StopPoint, vector<Edge>>> vertexMap;
        map<string, Edge> edgeMap;

        vector<string> tokenize(string s, string del = " ");
        double calculateWeights(string departureTime, string arrivalTime);
        void loadEdges(string fileName);
};
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
    /**
     * Function that loads all the nodes from the passed file
     @param file
     */
    void loadNode(string fileName);

    /**
     * Loads all the edges of the graph from trip_names.txt
     */
    void loadEdges();

    /**
     * Returns the map of each stopPoint to a vector of edges.
     */
    map<string, pair<StopPoint, vector<Edge>>> getVertexMap();

    /**
     * Returns the edge corresponding to the passed string.
     */
    map<string, Edge> getEdgeMap();

    private:
    map<string, pair<StopPoint, vector<Edge>>> vertexMap;
    map<string, Edge> edgeMap;

    vector<string> tokenize(string s, string del = " ");
    double calculateWeights(string departureTime, string arrivalTime);
    void loadEdges(string fileName);
};
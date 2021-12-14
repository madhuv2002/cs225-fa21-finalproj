#pragma once
#include "stoppoint.h"
#include "routemap.h"
#include "cs225/PNG.h"
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "visualizer.h"
#include "edge.h"
using namespace std;

class Traversal {
    public:
    /**
     * Constructor that creates a traversal using the created graph
     * @param routemap 
     */
    Traversal(RouteMap route);

    /**
     * Finds the shortest path between two points using Dijkstra's
     * @param s - starting point
     * @param e - ending point
     */
    vector<Edge> findShortestPath(string s, string e);

    /**
     * BFS traversal from a specific point
     * @param s - point to start the traversal
     */    
    vector<string> BFS(string s);

    /**
     * Dijkstra's algorithm from the starting point
     * @param s - start
     */
    map<string, string> Dijkstras(string s);

    private:
    RouteMap route_;

};
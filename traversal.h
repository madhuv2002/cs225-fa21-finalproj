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

    private:
        RouteMap route;

       map<string, string> BFS(string s);
       // map<string, string> Dijkstras(string s);
        
};
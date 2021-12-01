#pragma once 
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "stoppoint.h"
#include "stop.h"

class RouteMap {
    public:
        map<std::string, StopPoint> airportMap;
        void loadNode(std::string fileName);
        
         //std::vector<std::string> tokenize(string s, string del = " ");
};
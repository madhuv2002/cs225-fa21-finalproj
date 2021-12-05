#include "stoppoint.h"
#include "stop.h"
#include "routemap.h"
#include <fstream>
#include <string>
using namespace std;

int main() {
    RouteMap map; 
    map.loadNode("stops.csv");
    // std::cout << map.vertexMap["1STHZLWD:2"].getStopName();
    // std::cout << map.calculateWeights("08:08:30", "08:10:30");
    return 0;
}
#include "stoppoint.h"
#include "routemap.h"
#include <fstream>
#include <string>

#include "visualizer.h"
using namespace std;

int main() {
    RouteMap map; 
    map.loadNode("./assets/stops.csv");
    map.loadEdges();
    //cout << map.getEdgeMap().size() << endl;
    //cout << map.getEdgeMap()["JOHNLYN:3JOHNPRRE:3./assets/trips/BLUE.txt"].getWeight() << endl;

    Visualizer v;
    v.findLocation(map);
    // cout << v.origin.first << std::endl;
    // cout << v.endpoint.first << std::endl;
    // cout << v.scaleFactor.first << std::endl;
    return 0;
}
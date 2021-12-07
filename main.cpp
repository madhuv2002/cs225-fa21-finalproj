#include "stoppoint.h"
#include "routemap.h"
#include <fstream>
#include <string>
using namespace std;

int main() {
    RouteMap map; 
    map.loadNode("./assets/stops.csv");
    map.loadEdges();
    //cout << map.getEdgeMap().size() << endl;
    //cout << map.getEdgeMap()["JOHNLYN:3JOHNPRRE:3./assets/trips/BLUE.txt"].getWeight() << endl;
    return 0;
}
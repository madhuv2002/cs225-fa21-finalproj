#include "stoppoint.h"
#include "routemap.h"
#include "cs225/PNG.h"
#include <fstream>
#include <string>

#include "visualizer.h"
using namespace std;

int main() {
    RouteMap map; 
    map.loadNode("./assets/stops.csv");
    map.loadEdges();

    Visualizer v;
    v.findLocation(map);

    cs225::PNG* png = v.draw(map);
    png->writeToFile("map.png");
    delete png;

    return 0;
}
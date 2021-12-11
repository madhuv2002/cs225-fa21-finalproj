#include "stoppoint.h"
#include "routemap.h"
#include "cs225/PNG.h"
#include <fstream>
#include <string>

#include "visualizer.h"
using namespace std;

int main() {
    RouteMap route;
    route.loadNode("./assets/stops.csv");
    route.loadEdges();
    map<string, pair<StopPoint, vector<Edge>>> vertexMap = route.getVertexMap();
    cout << route.getEdgeMap().size() << endl;
    Visualizer v;
    v.findLocation(route);

    cs225::PNG* png = v.draw();
    png->writeToFile("map.png");

    delete png;
    return 0;
}
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


    //cout << map.getVertexMap().at("150DALE:1").second.size(); 
    // cout << map.getEdgeMap().size() << endl;
    //cout << map.getEdgeMap()["JOHNLYN:3JOHNPRRE:3./assets/trips/BLUE.txt"].getWeight() << endl;

    Visualizer v;
    v.findLocation(map);

    // for (auto pair: v.pointsMap) {
    //     cout << pair.second.first << " " << pair.second.second << endl;
    // }
    // cout << v.endpoint.first  - v.origin.first<< " " << v.endpoint.second - v.origin.second << endl;

    cs225::PNG* png = v.draw(map);
    png->writeToFile("map.png");
    delete png;

    return 0;
}
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
    //cout << map.getEdgeMap().size() << endl;
    //cout << map.getEdgeMap()["JOHNLYN:3JOHNPRRE:3./assets/trips/BLUE.txt"].getWeight() << endl;

    Visualizer v;
    v.findLocation(map);
    // // cout << v.origin.first << std::endl;
    // // cout << v.endpoint.first << std::endl;
    // // cout << v.scaleFactor.first << std::endl;
    // cs225::PNG* png = v.draw();
    // // for (size_t x = 0; x < 800; x++) {
    // //     for (size_t y = 0; y < 800; y++) {
    // //         cout << png->getPixel(x, y).h << endl;
    // //         cout << png->getPixel(x, y).s << endl;
    // //         cout << png->getPixel(x, y).l << endl;
    // //         cout << png->getPixel(x, y).a << endl;
    // //     }
    // // }
    // png->writeToFile("map.png");
    // delete png;
    return 0;
}
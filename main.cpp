#include "stoppoint.h"
#include "stop.h"
#include "routemap.h"
#include <fstream>
#include <string>
using namespace std;

int main() {
    RouteMap map; 
    map.loadNode("stops.csv");
    // std::cout << map.vertexMap["MTD5437"].getStopName();
    bool result = map.vertexMap["MTD5437"] ==  map.vertexMap["MTD5437"];
    std::cout << result << std::endl;
    return 0;
}
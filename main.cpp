#include "stoppoint.h"
#include "stop.h"
#include "routemap.h"
#include <fstream>
#include <string>
using namespace std;

int main() {
    RouteMap map; 
    map.loadNode("stops.csv");
    return 0;
}
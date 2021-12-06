#include "stoppoint.h"
#include "routemap.h"
#include <fstream>
#include <string>
using namespace std;

int main() {
    RouteMap map; 
    map.loadNode("stops.csv");
    
    std::cout << result << std::endl;
    return 0;
}
#include "stoppoint.h"
#include "routemap.h"
#include "cs225/PNG.h"
#include <fstream>
#include <string>
#include "traversal.h"
#include "visualizer.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    //making the graph
    RouteMap route;
    route.loadNode("./assets/stops.csv");
    route.loadEdges();
    
    //drawing the visualization
    Visualizer v;
    v.findLocation(route);

    cs225::PNG* png = v.draw();
    png->writeToFile("map.png");

    delete png;

    //traversing the graph
    Traversal t(route);

    vector<string> bfs = t.BFS(argv[1]);
    ofstream myfile;
    myfile.open ("bfs.txt");
    for (string v: bfs) {
        myfile <<  v << "\n";
    }
    myfile.close();
    
    vector<Edge> edges = t.findShortestPath(argv[1], argv[2]);
    
    for (Edge edge: edges) {
        cout << edge.getName() << endl;
    }
    return 0;
}
#include "traversal.h"

#include <queue>
#include <string>
#include <algorithm>
#include <limits.h>

Traversal::Traversal(RouteMap route) {
    route_ = route;
}

vector<Edge> Traversal::findShortestPath(string start, string end) {
    vector<Edge> path;
    map<string, string> parent = Dijkstras(start);
    map<string, pair<StopPoint, vector<Edge>>> vertexMap = route_.getVertexMap();
    string current = end;
    
    while (current != start) {
        string p = parent[current];
        vector<Edge> adjEdges = vertexMap[p].second;
        
        for (Edge edge: adjEdges) {
            if (edge.getEndPoint().getStopID() == current) {
                path.push_back(edge);
                break;
            }
        }
        current = p;
    }
    reverse(path.begin(), path.end());
    return path;
}

vector<string> Traversal::BFS(string start) {
    map<string, bool> visited;

    for (auto pair: route_.getVertexMap()) {
        visited[pair.first] = false;
    }

    queue<string> q;

    visited[start] = true;
    q.push(start);

    vector<string> bfs;
    
    while (!q.empty()) {
        string stop = q.front();
        bfs.push_back(stop);
        q.pop();
        
        for (unsigned idx = 0; idx < route_.getVertexMap()[stop].second.size(); idx++) {
            string adjStop = route_.getVertexMap()[stop].second[idx].getEndPoint().getStopID();
            
            if (!visited[adjStop]) {
                visited[adjStop] = true;
                q.push(adjStop);
            }
        }
    }

    return bfs;
}


map<string, string> Traversal::Dijkstras(string start) {
    map<string, string> parentMap;
    map<string, double> distanceMap;
    
    for (auto vertex : route_.getVertexMap()) {
        parentMap[vertex.first] = "";
        distanceMap[vertex.first] = INT_MAX;
    }

    distanceMap[start] = 0;

    vector<string> queue = BFS(start);

    for (string stop: queue) {
        for (unsigned idx = 0; idx < route_.getVertexMap()[stop].second.size(); idx++) {

            Edge edge = route_.getVertexMap()[stop].second[idx];
            string adjStop = edge.getEndPoint().getStopID();
            
            if (edge.getWeight() + distanceMap[stop] < distanceMap[adjStop]) {
                distanceMap[adjStop] = edge.getWeight() + distanceMap[stop];
                parentMap[adjStop] = stop;
            } 
        }
    }

    return parentMap;
}
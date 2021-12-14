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

    vector<string> r;
    
    while (!q.empty()) {
        s = q.front();
        r.push_back(s);
        q.pop();
        
        for (unsigned idx = 0; idx < route_.getVertexMap()[s].second.size(); idx++) {
            string i = route_.getVertexMap()[s].second[idx].getEndPoint().getStopID();
            
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return r;
}


map<string, string> Traversal::Dijkstras(string s) {
    map<string, string> parent;
    map<string, double> distance;
    
    for (auto v : route_.getVertexMap()) {
        parent[v.first] = "";
        distance[v.first] = INT_MAX;
    }

    distance[s] = 0;

    vector<string> queue = BFS(s);

    for (string temp: queue) {
        for (unsigned idx = 0; idx < route_.getVertexMap()[temp].second.size(); idx++) {
            Edge edge = route_.getVertexMap()[temp].second[idx];
            string i = edge.getEndPoint().getStopID();
            
            if (edge.getWeight() + distance[temp] < distance[i]) {
                distance[i] = edge.getWeight() + distance[temp];
                parent[i] = temp;
            } 
        }
    }

    return parent;
}
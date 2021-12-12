#include "traversal.h"
#include <queue>
#include <string>
#include <limits.h>

vector<Edge> Traversal::findShortestPath(string s, string e) {
    vector<Edge> path;
    map<string, string> parent = Dijkstras(s);
    map<string, pair<StopPoint, vector<Edge>>> vertexMap = route.getVertexMap();
    string current = e;
    while (true) {
        string p = parent[current];
        vector<Edge> adjEdges = vertexMap[p].second;
        for (Edge edge: adjEdges) {
            if (edge.getEndPoint().getStopID() == current) {
                path.push_back(edge);
                break;
            }
        }
        if (p == s) {
            break;
        }
        // path.push_back();
    }
}

vector<string> Traversal::BFS(string s) {
    map<string, bool> visited;

    map<string, string> parent;
    map<string, double> distance;

    for (auto pair: route.getVertexMap()) {
        visited[pair.first] = false;

        parent[pair.first] = "";
        distance[pair.first] = INT_MAX;
    }

    queue<string> q;

    visited[s] = true;
    q.push(s);

    vector<string> r;
    distance[s] = 0;

    while (!q.empty()) {
        s = q.front();
        r.push_back(s);
        q.pop();

        for (Edge edge: route.getVertexMap()[s].second) {
            string i = edge.getStartPoint().getStopName();
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
    
    for (auto v : route.getVertexMap()) {
        parent[v.first] = "";
        distance[v.first] = INT_MAX;
    }

    distance[s] = 0;

    vector<string> queue = BFS(s);

    for (unsigned i = 0; i < queue.size(); i++) {
        string temp = queue.front();
        queue.erase(queue.begin());
        
        for (Edge edge: route.getVertexMap()[temp].second) {
            string i = edge.getStartPoint().getStopName();
            if (edge.getWeight() + distance[s] < distance[i]) {
                distance[i] = edge.getWeight() + distance[temp];
                parent[i] = s;
            } 
        }
    }

    return parent;
}
#include "traversal.h"
#include <queue>
#include <string>
#include <algorithm>
#include <limits.h>

Traversal::Traversal(RouteMap route) {
    route_ = route;
}

vector<Edge> Traversal::findShortestPath(string s, string e) {
    vector<Edge> path;
    map<string, string> parent = Dijkstras(s);
    map<string, pair<StopPoint, vector<Edge>>> vertexMap = route_.getVertexMap();
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
        current = p;
        if (p == s) {
            break;
        }
    }
    reverse(path.begin(), path.end());
    return path;
}

vector<string> Traversal::BFS(string s) {
    map<string, bool> visited;

    for (auto pair: route_.getVertexMap()) {
        visited[pair.first] = false;
    }

    queue<string> q;

    visited[s] = true;
    q.push(s);

    vector<string> r;
    cout << visited.size() << endl;

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

    for (auto pair: visited) {
        if (!pair.second) {
            cout << pair.first << endl;
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

    for (unsigned i = 0; i < queue.size(); i++) {
        string temp = queue.front();
        queue.erase(queue.begin());
        
        for (Edge edge: route_.getVertexMap()[temp].second) {
            string i = edge.getStartPoint().getStopName();
            if (edge.getWeight() + distance[s] < distance[i]) {
                distance[i] = edge.getWeight() + distance[temp];
                parent[i] = s;
            } 
        }
    }

    return parent;
}
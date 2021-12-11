#include "traversal.h"
#include <queue>
#include <string>

vector<string> Traversal::BFS(string s) {
    map<string, bool> visited;
    for (auto pair: route.getVertexMap()) {
        visited[pair.first] = false;
    }

    queue<string> q;

    visited[s] = true;
    q.push(s);

    vector<string> r;

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
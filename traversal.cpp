#include "traversal.h"
#include <queue>
#include <string>

map<string, string> Traversal::BFS(string s) {
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

   // vector<string> r;
    distance[s] = 0;

    while (!q.empty()) {
        s = q.front();
       // r.push_back(s);
        q.pop();

        for (Edge edge: route.getVertexMap()[s].second) {
            string i = edge.getStartPoint().getStopName();
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
            if (edge.getWeight() + distance[s] < distance[i]) {
                distance[i] = edge.getWeight() + distance[s];
                parent[i] = s;
            }
        }
    }

    return parent;
}


// map<string, string> Traversal::Dijkstras(string s) {
//     map<string, string> parent;
//     map<string, double> distance;
//     map<string, bool> visited;
//     for (auto v : route.getVertexMap()) {
//         parent[v.first] = "";
//         distance[v.first] = INT_MAX;
//     }

//     distance[s] = 0;
//     vector<string> queue = BFS(s);
//     for (unsigned i = 0; i < queue.size(); i++) {
//         string temp = queue.begin();
//         queue.erase(queue.begin());
//         visited[temp] = true;
//         for ()
//     }


//     return distance;
// }
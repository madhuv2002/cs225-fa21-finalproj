#include <vector>
#include <list>

#include "routemap.h"

using namespace std;

void RouteMap::loadNode(string fileName) {
    ifstream file;

    file.open(fileName);

    if (file.is_open()) {
        for (string line; getline(file, line); ) {

            vector<string> slicedStop =  tokenize(line, ",");
            int count = 0;

            while (count < static_cast<int>(slicedStop.size())) {
                if (count > 3 && (count + 5) < static_cast<int>(slicedStop.size()) && !slicedStop.at(count).empty()) {

                    StopPoint stp(slicedStop[count], slicedStop[count + 1], stod(slicedStop[count + 2]),
                     stod(slicedStop[count + 3]), slicedStop[count + 4]);
                    vector<Edge> edges;
                    std::pair<StopPoint, vector<Edge>> pair;
                    pair.first = stp;
                    pair.second = edges;
                    vertexMap.insert({slicedStop[count + 1], pair});
                     
                    count += 5;
                } else {
                    count++;
                }
            }

        }
    }
    file.close();
}


void RouteMap::loadEdges() {
    ifstream file;
    vector<string> fileNames;
    file.open("./assets/trip_names.txt");
    if (file.is_open()) {
        for (string line; getline(file, line); ) {
            loadEdges("./assets/trips/" + line);
        }
    }
    file.close();
}

map<string, pair<StopPoint, vector<Edge>>> RouteMap::getVertexMap() {
    return vertexMap;
}

map<string, Edge> RouteMap::getEdgeMap() {
    return edgeMap;
}

void RouteMap::loadEdges(string fileName) {
    ifstream file;
    // fileName = fileName.substr(0, fileName.size()-1);
    // file.open(fileName, std::ifstream::in);
    file.open(fileName);
    if (file.is_open()) {
        
        string line;
        getline(file, line);
        vector<string> slicedTime1 =  tokenize(line, ",");
        getline(file, line);
        vector<string> slicedStop1 = tokenize(line, ",");
        while (getline(file, line)) {
            vector<string> slicedTime2 =  tokenize(line, ",");
            getline(file, line);
            vector<string> slicedStop2 = tokenize(line, ",");
            
            string name = slicedStop1[1] + slicedStop2[1] + fileName;
            StopPoint stp1(slicedStop1[0], slicedStop1[1], stod(slicedStop1[2]), stod(slicedStop1[3]), slicedStop1[4]);
            StopPoint stp2(slicedStop2[0], slicedStop2[1], stod(slicedStop2[2]), stod(slicedStop2[3]), slicedStop2[4]);
            double weight = calculateWeights(slicedTime1[1], slicedTime2[0]);
            Edge edge(name, stp1, stp2, weight, fileName);
            edgeMap.insert({name, edge});

            vertexMap[slicedStop1[1]].second.push_back(edge);
            
            slicedTime1 = slicedTime2;
            slicedStop1 = slicedStop2;
        }
    }
    file.close();
}

vector<string> RouteMap::tokenize(string s, string del) {
    int start = 0;
    int end = s.find(del);
    vector<string> slicedStr;

    while (end != -1) {
        slicedStr.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }

    slicedStr.push_back(s.substr(start, end - start));
    return slicedStr;
}

double RouteMap::calculateWeights(string departureTime, string arrivalTime) {
    vector<string> slicedDepTime =  tokenize(departureTime, ":");
    vector<string> slicedArrTime =  tokenize(arrivalTime, ":");

    double dep = (stod(slicedDepTime.at(0))*60) + stod(slicedDepTime.at(1)) + ((double)stod(slicedDepTime.at(2)) / 60);
    double arr = (stod(slicedArrTime.at(0))*60) + stod(slicedArrTime.at(1)) + ((double)stod(slicedArrTime.at(2)) / 60); 

    return arr - dep;
}

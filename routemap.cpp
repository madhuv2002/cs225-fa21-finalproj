#include "routemap.h"

using namespace std;

 std::vector<std::string> tokenize(string s, string del = " ") {
    int start = 0;
    int end = s.find(del);
    std::vector<std::string> slicedStr;

    while (end != -1) {
        slicedStr.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }

    slicedStr.push_back(s.substr(start, end - start));
    return slicedStr;
}

void RouteMap::loadNode(string fileName) {
    // testing it out with stops file first
    std::ifstream file;

    file.open(fileName);

    if (file.is_open()) {
        for (std::string line; std::getline(file, line); ) {
            // uncomment to view every stop
            //std::cout << line << '\n';

            std::vector<std::string> slicedStop =  tokenize(line, ",");
            int count = 0;

            // uncomment to view every stop point
            // int idx = 0;
            // for (std::string elem : slicedStop) {
            //     if (elem.empty()) {
            //         continue;
            //         //std::cout << slicedStop.erase(slicedStop.begin() + (idx)) << '\n';
            //     } else {
            //         std::cout << elem << '\n';
            //     }
            //     idx++;
            // }

            while (count < slicedStop.size()) {
                if (count > 3 && (count + 5) < slicedStop.size() && !slicedStop.at(count).empty()) {
                     //std::cout << slicedStop.at(count) << '\n';
                    StopPoint stp(slicedStop.at(count), slicedStop.at(count + 1), slicedStop.at(count + 2),
                     slicedStop.at(count + 3), slicedStop.at(count + 4));
                     vertexMap.insert({slicedStop.at(count), stp});
                     
                    count += 5;
                } else {
                    count++;
                }
            }

        }
    }
   
}

void RouteMap::loadEdges() {
    
}

void RouteMap::loadEdges(std::string fileName) {

}

double RouteMap::calculateWeights(std::string departureTime, std::string arrivalTime) {
    std::vector<std::string> slicedDepTime =  tokenize(departureTime, ":");
    std::vector<std::string> slicedArrTime =  tokenize(arrivalTime, ":");

    double dep = (std::stod(slicedDepTime.at(0))*60) + std::stod(slicedDepTime.at(1)) + ((double)std::stod(slicedDepTime.at(2)) / 60);
    double arr = (std::stod(slicedArrTime.at(0))*60) + std::stod(slicedArrTime.at(1)) + ((double)std::stod(slicedArrTime.at(2)) / 60); 

    return arr - dep;
}

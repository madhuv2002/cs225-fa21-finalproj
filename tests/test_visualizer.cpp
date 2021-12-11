#include "../cs225/catch/catch.hpp"
#include <string>
#include <map>
#include "../routemap.h"
#include "../visualizer.h"

#include <iostream>

using namespace std;

TEST_CASE("Visualizer tests") {
    RouteMap route;
    route.loadNode("./assets/stops.csv");
    map<string, pair<StopPoint, vector<Edge>>> vertexMap = route.getVertexMap();
    route.loadEdges();
    
    Visualizer v;

    v.findLocation(route);

    SECTION("Check for accurate origin") {
        REQUIRE(v.origin.first == 40.048065);
        REQUIRE(v.origin.second == -88.322875);
    }

    SECTION("Check for accurate displacement") {
        REQUIRE(v.displacement.first == Approx(911.6414090773));
        REQUIRE(v.displacement.second == Approx(425.9858424246));
    }

    SECTION("Check for accurate endpoints") {
        REQUIRE(v.endpoint.first == Approx(5139.55));
        REQUIRE(v.endpoint.second == Approx(5532.48));
    }

    SECTION("Check for accurate location map") {
        for (auto pair : v.pointsMap) {
            REQUIRE(pair.second.first > v.origin.first);
            REQUIRE(pair.second.first < v.endpoint.first);
            REQUIRE(pair.second.second > v.origin.second);
            REQUIRE(pair.second.second < v.endpoint.second);
        }
        
    }

    cs225::PNG* png = v.draw();
    png->writeToFile("map.png");
    delete png;

}
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
    route.loadEdges();
    
    Visualizer v;

    v.findLocation(route);

    SECTION("Check for accurate origin") {
        REQUIRE(v.origin.first == -88.322875);
        REQUIRE(v.origin.second == 40.048065);
    }

    SECTION("Check for accurate displacement") {
        REQUIRE(v.displacement.first == Approx(425.9858424246));
        REQUIRE(v.displacement.second == Approx(1139.5517613466));
    }

    SECTION("Check for accurate endpoints") {
        REQUIRE(v.endpoint.first == Approx(5532.48));
        REQUIRE(v.endpoint.second == Approx(6424.4397016833));
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
    png->writeToFile("testmap.png");
    delete png;
}
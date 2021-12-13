#include "../cs225/catch/catch.hpp"

#include "../routemap.h"
#include "../traversal.h"

#include <iostream>

using namespace std;

TEST_CASE("Traversal tests") {
    RouteMap routeMap;
    routeMap.loadNode("./assets/stops.csv");
    routeMap.loadEdges();
    
    Traversal t(routeMap);
    
    SECTION("BFS traversal has correct size") {
        vector<string> path = t.BFS("1STSMR:4");
        REQUIRE(path.size() == 1421);
        path = t.BFS("WDSRSTLW:1");
        REQUIRE(path.size() == 1421);
        path = t.BFS("E14:2");
        REQUIRE(path.size() == 1421);
    }

    SECTION("Dijkstras algorithm has correct size") {
        map<string, string> path = t.Dijkstras("1STSMR:4");
        REQUIRE(path.size() == 1976);
        REQUIRE(path["1STSMR:4"] == "");
        REQUIRE(path["1STHZLWD:4"] == "1STSMR:4");
        path = t.Dijkstras("WDSRSTLW:1");
        REQUIRE(path.size() == 1976);
        REQUIRE(path["WDSRSTLW:1"] == "");
        REQUIRE(path["WDSRCLSL:1"] == "WDSRSTLW:1");
        path = t.Dijkstras("E14:2");
        REQUIRE(path.size() == 1976);
        REQUIRE(path["E14:2"] == "");
    }

    SECTION("findShortestPath same stop") {
        vector<Edge> path = t.findShortestPath("1STSMR:4", "1STSMR:4");
        REQUIRE(path.size() == 0);
    }

    SECTION("findShortestPath 1 stop apart") {
        vector<Edge> path = t.findShortestPath("1STSMR:4", "1STHZLWD:4");
        REQUIRE(path.size() == 1);
        REQUIRE(path[0].getName() == "1STSMR:41STHZLWD:41 YELLOW ALT");
        REQUIRE(path[0].getRoute() == "1 YELLOW ALT");
    }

    SECTION("findShortestPath same route") {
        vector<Edge> path = t.findShortestPath("1STSMR:4", "CHCHLYN:8");
        REQUIRE(path.size() == 28);
        REQUIRE(path[0].getName() == "1STSMR:41STHZLWD:41 YELLOW ALT");
        REQUIRE(path[0].getRoute() == "1 YELLOW ALT");
        REQUIRE(path[27].getName() == "CHCHELM:1CHCHLYN:81 YELLOW ALT");
        REQUIRE(path[27].getRoute() == "1 YELLOW ALT");
    }
}

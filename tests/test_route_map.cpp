#include "../cs225/catch/catch.hpp"

#include "../routemap.h"

#include <iostream>

using namespace std;

TEST_CASE("RouteMap tests") {
    RouteMap routeMap;
    routeMap.loadNode("./assets/stops.csv");
    map<string, pair<StopPoint, vector<Edge>>> vertexMap = routeMap.getVertexMap();
    
    SECTION("vertexMap size") {
        REQUIRE(vertexMap.size() == 1975);
    }

    SECTION("First Stop") {
        REQUIRE(vertexMap["150DALE:1"].first.getStopLatitude() == 40.114512);
        REQUIRE(vertexMap["150DALE:1"].first.getStopLongitude() == -88.180673);
        REQUIRE(vertexMap["150DALE:1"].first.getStopName() == "U.S. 150 & Dale (NE Corner)");
        REQUIRE(vertexMap["150DALE:1"].second.empty());
    }

    SECTION("Last Stop") {
        REQUIRE(vertexMap["YMCA:2"].first.getStopLatitude() == 40.081572);
        REQUIRE(vertexMap["YMCA:2"].first.getStopLongitude() == -88.309155);
        REQUIRE(vertexMap["YMCA:2"].first.getStopName() == "Stephens Family YMCA (East Side)");
        REQUIRE(vertexMap["YMCA:2"].second.empty());
    }

    routeMap.loadEdges();
    vertexMap = routeMap.getVertexMap();
    map<string, Edge> edgeMap = routeMap.getEdgeMap();

    SECTION("edgeMap size") {
        REQUIRE(edgeMap.size() == 4002);
    }

    SECTION("First edge weight") {
        REQUIRE(vertexMap["1STSMR:4"].second.size() > 0);
        REQUIRE(edgeMap["1STSMR:41STHZLWD:4./assets/trips/1 YELLOW ALT.txt"].getWeight() == 0.5);

    }

    SECTION("Last edge weight") {
        REQUIRE(vertexMap["1STSTDM:4"].second.size() > 0);
        REQUIRE(edgeMap["1STSTDM:4E14:2./assets/trips/YELLOWHOPPER.txt"].getWeight() == 3.5);
    }
}
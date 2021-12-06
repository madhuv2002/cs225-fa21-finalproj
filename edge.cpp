#include <string>
#include "edge.h"

using namespace std;

Edge::Edge(StopPoint start, StopPoint end, double weight, string route)
    : start_(start), end_(end), name_(start_.getStopID() + end_.getStopID()), weight_(weight), route_(route)
{ }

Edge::Edge() : start_(), end_(), name_(""), weight_(0), route_("")
{ }

void Edge::setStartPoint(StopPoint t) {
    start_ = t;
}

StopPoint Edge::getStartPoint() {
    return start_;
}

void Edge::setEndPoint(StopPoint t) {
    end_ = t;
}

StopPoint Edge::getEndPoint() {
    return end_;
}

void Edge::setWeight(double t) {
    weight_ = t;
}

double Edge::getWeight() {
    return weight_;
}

void Edge::setRoute(string route) {
    route_ = route;
}

string Edge::getRoute() {
    return route_;
}
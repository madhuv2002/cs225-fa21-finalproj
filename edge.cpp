#include <string>
#include "edge.h"

using namespace std;

Edge::Edge(string name, StopPoint start, StopPoint end, double weight, string route)
    : name_(name), start_(start), end_(end), weight_(weight), route_(route)
{ }

Edge::Edge() : name_(""), start_(), end_(), weight_(0.0), route_("")
{ }

void Edge::setName(string name) {
    name_ = name;
}

string Edge::getName() {
    return name_;
}

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

bool Edge::operator==(const Edge& rhs) const {
   return name_ == rhs.name_ && start_ == rhs.start_ 
    && end_ == rhs.end_ && weight_ == rhs.weight_; 
}
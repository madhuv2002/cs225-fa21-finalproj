#include <string>
#include <edge.h>

using namespace std;

Edge::Edge(StopPoint begin_, StopPoint final_)
    : start_(begin_), end_(final_), name_(start_.getStopID() + end_.getStopID()), weight_(1)
{ }

Edge::Edge() : start_(), end_(), name_(""), weight_(0)
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
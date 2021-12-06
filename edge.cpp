#include <string>
#include <edge.h>

using namespace std;

Edge::Edge(StopPoint start, StopPoint end, double weight)
    : start_(start), end_(end), name_(start_.getStopID() + end_.getStopID()), weight_(weight)
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

bool Edge::operator==(const Edge& rhs) const {
   return name_ == rhs.name_ && start_ == rhs.start_ 
    && end_ == rhs.end_ && weight_ == rhs.weight_; 
}
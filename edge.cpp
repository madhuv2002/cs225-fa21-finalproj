#include <string>
#include <edge.h>

using namespace std;

Edge::Edge(StopPoint begin, StopPoint final)
        : start(begin), end(final), name(begin.getStopID() + end.getStopID())
    { }

Edge::Edge() : start(), end(), name("")
    { }

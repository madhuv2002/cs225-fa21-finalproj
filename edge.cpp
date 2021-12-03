#include <string>
#include <edge.h>

using namespace std;

Edge::Edge(StopPoint begin_, StopPoint final_)
        : start(begin_), end(final_), name(start.getStopID() + end.getStopID())
    { }

Edge::Edge() : start(), end(), name("")
    { }

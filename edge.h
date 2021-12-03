#pragma once

#include <string>
#include <stoppoint.h>
using namespace std;

class Edge {
  public:
    StopPoint start;
    StopPoint end; 
    /**
     * Edge constructor.
     * @param begin - starting point
     * @param final - ending point
     */
    Edge(StopPoint begin, StopPoint final);

    /**
     * Default constructor.
     */
    Edge();

private:
    string name; 
};
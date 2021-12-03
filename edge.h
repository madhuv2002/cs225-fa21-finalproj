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
    Edge(StopPoint begin_, StopPoint final_);

    /**
     * Default constructor.
     */
    Edge();

private:
    string name; 
};
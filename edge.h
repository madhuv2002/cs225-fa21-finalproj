#pragma once

#include <string>
#include "stoppoint.h"
using namespace std;

class Edge {
  public:
    /**
     * Edge constructor.
     * @param name - the name of the edge
     * @param start - starting point
     * @param end - ending point
     * @param weight 
     * @param route - the route the edge is on
     */
    Edge(string name, StopPoint start, StopPoint end, double weight, string route);

    /**
     * Default constructor.
     */
    Edge();

    /**
     * Function to set the name of the edge
     * @param name
     */
    void setName(string name);

    /**
     * Getter function for the name of the edge
     */
    string getName();

    /**
     * Function to set the starting point of the edge
     * @param t
     */
    void setStartPoint(StopPoint t);

    /**
     * Getter function for the starting point of the edge
     */
    StopPoint getStartPoint();

    /**
     * Function to set the end point of the edge
     * @param t
     */
    void setEndPoint(StopPoint t);

    /**
     * Getter function for the ending point of the edge
     */  
    StopPoint getEndPoint();

    /**
     * Function to set the weight of the edge
     * @param t
     */
     void setWeight(double t);

    /**
     * Getter function for the weight of the edge
     */    
    double getWeight();
    bool operator==(const Edge& rhs) const;

    /**
     * Function to set the route of the edge
     * @param route
     */
    void setRoute(string route);

    /**
     * Getter function for the route the edge is on
     */    
    string getRoute();

    /**
     * Destructor
     */
    ~Edge() {}

private:
    string name_; 
    StopPoint start_;
    StopPoint end_; 
    double weight_;
    string route_;
};
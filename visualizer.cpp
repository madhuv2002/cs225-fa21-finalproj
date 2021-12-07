#include "visualizer.h"

void Visualizer::setLocation(RouteMap map) {
    // figure out the minimum and maximum distances for x and y directions and store them 
    double minLat = INT_MAX;
    double minLon = INT_MAX; 

    double maxLat = INT_MIN;
    double maxLon = INT_MIN;

     for (StopPoint stop : map.getVertexMap().values().first) {
         if (stop.getStopLatitude() < minLat) {
             minLat = stop.getStopLatitude();
         }

         if (stop.getStopLongitude() < minLon) {
             minLon = stop.getStopLongitude();
         }

         if (stop.getStopLatitude() > maxLat) {
             maxLat = stop.getStopLatitude();
         }

         if (stop.getStopLongitude() > maxLon) {
             maxLon = stop.getStopLongitude();
         }
     }

     origin = make_pair(minLat, minLon);

    // find the scale factor 
    scaleFactor = make_pair((double) 800 /(maxLat - minLat), (double) 800 /(maxLon - minLon));

    // find the minimum distance bwetween two points and scale that distance in order to create the displacement point

    double minDistance = INT_MAX;

    for (StopPoint stop : map.getVertexMap().values().first) {
        double dist = sqrt((pow((stop.getStopLatitude() - origin.first)), 2.0)) + 
                            (pow((stop.getStopLongitude() - origin.second), 2.0)));

        if (dist < minDistance && dist > 0) {
            minDist = dist;
            displacement.first = stop.getStopLatitude() - origin.first;
            displacement.second = stop.getStopLongitude() - origin.second;
        }
    }

    //set endpoint
    endpoint.first = (maxLat*scaleFactor.first) + (2*displacement.first);
    endpoint.second = (maxLat*scaleFactor.second) + (2*displacement.second);

    // set the locations 
    for (StopPoint stop : map.getVertexMap().values().first) {
        double x = (stop.getStopLatitude()*scaleFactor.first) + displacement.first;
        double y = (stop.getStopLongitude()*scaleFactor.second) + displacement.second;
        pointsMap.insert({stop, std::make_pair(x, y)});
    }
}

double Visualizer::calculateWeight(StopPoint point, RouteMap map) {
    // increment weight by the number of edges coming out of the passed stop point
    return map.getVertexMap()[point.getStopName()].second.size();
}
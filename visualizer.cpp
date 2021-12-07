#include "visualizer.h"

void Visualizer::findLocation(RouteMap map) {
    // figure out the minimum and maximum distances for x and y directions and store them 
    double minLat = INT_MAX;
    double minLon = INT_MAX; 

    double maxLat = INT_MIN;
    double maxLon = INT_MIN;

     for (auto pair : map.getVertexMap()) {
         StopPoint stop = pair.second.first;
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
    scaleFactor.first = (double) 800 / (maxLat - minLat);
    scaleFactor.second = (double) 800 / (maxLon - minLon);

    // find the minimum distance bwetween two points and scale that distance in order to create the displacement point

    double minDistance = INT_MAX;

    for (auto pair : map.getVertexMap()) {
        StopPoint stop = pair.second.first;
        double dist = sqrt(pow((stop.getStopLatitude() - origin.first), 2.0) + 
                            pow((stop.getStopLongitude() - origin.second), 2.0));

        if (dist < minDistance && dist > 0) {
            minDistance = dist;
            displacement.first = stop.getStopLatitude() - origin.first;
            displacement.second = stop.getStopLongitude() - origin.second;
        }
    }

    //set endpoint
    endpoint.first = ((maxLat - origin.first)*scaleFactor.first) + (2*displacement.first);
    endpoint.second = ((maxLat - origin.second)*scaleFactor.second) + (2*displacement.second);

    // set the locations 
    for (auto pair : map.getVertexMap()) {
        StopPoint stop = pair.second.first;
        std::pair<double, double> point;
        point.first = (stop.getStopLatitude()*scaleFactor.first) + displacement.first;
        point.second = (stop.getStopLongitude()*scaleFactor.second) + displacement.second;

        pointsMap.insert({stop, point});
    }
}

double Visualizer::calculateWeight(StopPoint point, RouteMap map) {
    // increment weight by the number of edges coming out of the passed stop point
    return map.getVertexMap()[point.getStopName()].second.size();
}
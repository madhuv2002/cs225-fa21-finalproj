#include "visualizer.h"
#include <limits.h>

void Visualizer::findLocation(RouteMap map) {
    // figure out the minimum and maximum distances for x and y directions and store them 
    double minLat = INT_MAX;
    double minLon = INT_MAX; 

    double maxLat = INT_MIN;
    double maxLon = INT_MIN;
    auto vertexMap = map.getVertexMap();

     for (auto pair : vertexMap) {
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

    origin = make_pair(minLon, maxLat);

    // find the scale factor 
    scaleFactor.first = (double) 800 / (minLon - maxLon);
    scaleFactor.second = (double) 800 / (maxLat - minLat);
    for (auto pair : vertexMap) {
        StopPoint stop = pair.second.first;
        std::pair<double, double> point;
        point.first = (stop.getStopLongitude() - minLon)*scaleFactor.first;
        point.second = (stop.getStopLatitude() - maxLat)*scaleFactor.second;
        pointsMap.insert({stop, point});
        cout << point.first << " " << point.second << endl;
    }

    // find the minimum distance bwetween two points and scale that distance in order to create the displacement point

    // double minDistance = INT_MAX;

    // for (auto pair : map.getVertexMap()) {
    //     StopPoint stop = pair.second.first;
    //     double dist = sqrt(pow((stop.getStopLatitude() - origin.first), 2.0) + 
    //                         pow((stop.getStopLongitude() - origin.second), 2.0));

    //     if (dist < minDistance && dist > 0) {
    //         minDistance = dist;
    //         displacement.first = stop.getStopLatitude() - origin.first;
    //         displacement.second = stop.getStopLongitude() - origin.second;
    //     }
    // }

    // //set endpoint
    // endpoint.first = ((maxLat - origin.first)*scaleFactor.first) + (2*displacement.first);
    // endpoint.second = ((maxLon - origin.second)*scaleFactor.second) + (2*displacement.second);

    // // set the locations 
    // for (auto pair : map.getVertexMap()) {
    //     StopPoint stop = pair.second.first;
    //     std::pair<double, double> point;
    //     point.first = (stop.getStopLatitude()*scaleFactor.first) + displacement.first - origin.first;
    //     point.second = (stop.getStopLongitude()*scaleFactor.second) + displacement.second - origin.second;

    //     pointsMap.insert({stop, point});
    // }
}

double Visualizer::calculateWeight(StopPoint point, RouteMap map) {
    // increment weight by the number of edges coming out of the passed stop point
    return map.getVertexMap()[point.getStopName()].second.size();
}

cs225::PNG* Visualizer::draw() const {
    cs225::PNG* png = new cs225::PNG(800,800);
    for (auto pair : pointsMap) {
        cout << pair.second.first << " " << pair.second.second << endl;
        for (size_t x = pair.second.first - 10; x <= pair.second.first + 10; x++) {
            for (size_t y = pair.second.second - 10; y <= pair.second.second + 10; y++) {
                cout << x << " " << y << endl;
                png->getPixel(x, y).h = 240;
                png->getPixel(x, y).s = 1;
                png->getPixel(x, y).l = 0.5;
                png->getPixel(x, y).a = 1;
            }
        }
    }

    return png;
}
#include "visualizer.h"
#include <limits.h>

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
    scaleFactor.first = (double) 4000 / (maxLat - minLat);
    scaleFactor.second = (double) 5000 / (maxLon - minLon);

    // find the minimum distance bwetween two points and scale that distance in order to create the displacement point

    double minDistance = INT_MAX;

    for (auto pair : map.getVertexMap()) {
        StopPoint stop = pair.second.first;
        double dist = sqrt(pow((stop.getStopLatitude() - origin.first), 2.0) + 
                            pow((stop.getStopLongitude() - origin.second), 2.0));

        if (dist < minDistance && dist > 0) {
            minDistance = dist;
            displacement.first = (stop.getStopLatitude() - origin.first)*scaleFactor.first;
            displacement.second = (stop.getStopLongitude() - origin.second)*scaleFactor.second;
        }
    }

    //set endpoint
    endpoint.first = ((maxLat - origin.first)*scaleFactor.first) + (1.25*displacement.first);
    endpoint.second = ((maxLon - origin.second)*scaleFactor.second) + (1.25*displacement.second);

    // set the locations 
    for (auto pair : map.getVertexMap()) {
        StopPoint stop = pair.second.first;
        std::pair<double, double> point;
        point.first = ((stop.getStopLatitude() - origin.first)*scaleFactor.first) + displacement.first;
        point.second = ((stop.getStopLongitude() - origin.second)*scaleFactor.second) + displacement.second;

        pointsMap.insert({stop, point});
    }
}

double Visualizer::calculateWeight(StopPoint point, RouteMap map) {
    // increment weight by the number of edges coming out of the passed stop point
    return map.getVertexMap()[point.getStopName()].second.size();
}

cs225::PNG* Visualizer::draw(RouteMap map) const {
    cs225::PNG* png = new cs225::PNG(endpoint.first  - origin.first, endpoint.second - origin.second);
    for (auto pair : pointsMap) {
        // cout << pair.second.first << " " << pair.second.second <<  endl;
        for (size_t x = pair.second.first - 10; x <= pair.second.first + 10; x++) {
            for (size_t y = pair.second.second - 10; y <= pair.second.second + 10; y++) {
                png->getPixel(x, y).h = 240;
                png->getPixel(x, y).s = 1;
                png->getPixel(x, y).l = 0.5;
                png->getPixel(x, y).a = 1;
            }
        }
        // drawEdges(pair, map, png);
    }

    return png;
}

void Visualizer::drawEdges(std::pair<StopPoint, std::pair<double, double>> pair, RouteMap map, cs225::PNG* png) const{
    vector<Edge> edges = map.getVertexMap()[pair.first.getStopName()].second;

    for (unsigned int i = 0; i < edges.size(); i++) {
        StopPoint destination = edges[i].getEndPoint();
        double endY = pointsMap.at(destination).second;
        double endX = pointsMap.at(destination).first;
        //double dist = sqrt(pow((pointsMap[edges.getEndPoint()].first - pointsMap[edges.getStartPoint()].first), 2.0) + pow((pointsMap[edges.getEndPoint()].first - pointsMap[edges.getStartPoint()].second), 2.0));
        double slope = (double)(endY - pair.second.second)/ (endX - pair.second.first);

        for (size_t x = pair.second.first - 3; x <= endX + 3; x++) {
            for (size_t y = pair.second.second - 3; y <= endY + 3; y+= slope*x) {
                png->getPixel(x, y).h = 0;
                png->getPixel(x, y).s = 0;
                png->getPixel(x, y).l = 0;
                png->getPixel(x, y).a = 1;
            }
        }
    }

}
#include "visualizer.h"
#include <limits.h>

void Visualizer::findOrigin() {
    minLat = INT_MAX;
    minLon = INT_MAX; 

    maxLat = INT_MIN;
    maxLon = INT_MIN;
     for (auto pair : vertexMap) {
         StopPoint stop = pair.second.first;
         if (stop.getStopLatitude() < minLat && stop.getStopLatitude() != 0) {
             minLat = stop.getStopLatitude();
         }

         if (stop.getStopLongitude() < minLon) {
             minLon = stop.getStopLongitude();
         }

         if (stop.getStopLatitude() > maxLat) {
             maxLat = stop.getStopLatitude();
         }

         if (stop.getStopLongitude() > maxLon && stop.getStopLongitude() != 0) {
             maxLon = stop.getStopLongitude();
         }
     }
     origin = make_pair(minLat, minLon);

     // find the scale factor 
    scaleFactor.first = (double) 4000 / (maxLat - minLat);
    scaleFactor.second = (double) 5000 / (maxLon - minLon);
}

void Visualizer::calculateMinDistance() {
    double minDistance = INT_MAX;

    for (auto pair : vertexMap) {
        StopPoint stop = pair.second.first;
        double dist = sqrt(pow((stop.getStopLatitude() - origin.first), 2.0) + 
                            pow((stop.getStopLongitude() - origin.second), 2.0));

        if (dist < minDistance && dist > 0) {
            minDistance = dist;
            displacement.first = (stop.getStopLatitude() - origin.first)*scaleFactor.first;
            displacement.second = (stop.getStopLongitude() - origin.second)*scaleFactor.second;
        }
    }
}

void Visualizer::findLocation(RouteMap map) {
    routeMap = map;
    vertexMap = routeMap.getVertexMap();
    // figure out the minimum and maximum distances for x and y directions and store them 
    findOrigin();

    // find the minimum distance bwetween two points and scale that distance in order to create the displacement point
    calculateMinDistance();

    //set endpoint
    endpoint.first = ((maxLat - origin.first)*scaleFactor.first) + (1.25*displacement.first);
    endpoint.second = ((maxLon - origin.second)*scaleFactor.second) + (1.25*displacement.second);
    
    // set the locations 
    for (auto pair : vertexMap) {
        StopPoint stop = pair.second.first;
        std::pair<double, double> point;
        point.first = ((stop.getStopLatitude() - origin.first)*scaleFactor.first) + displacement.first;
        point.second = ((stop.getStopLongitude() - origin.second)*scaleFactor.second) + displacement.second;
        if (stop.getStopLatitude() != 0 && stop.getStopLongitude() != 0) {
            pointsMap.insert({stop, point});
        }
        //cout << point.first << " " << point.second << endl;
        //pointsMap.insert({stop, point});
    }
}

double Visualizer::calculateWeight(StopPoint point) {
    // increment weight by the number of edges coming out of the passed stop point
    return vertexMap[point.getStopName()].second.size();
}

cs225::PNG* Visualizer::draw() {
    png = new cs225::PNG(endpoint.first  - origin.first, endpoint.second - origin.second);
    for (auto pair : pointsMap) {
        //cout << pair.second.first << " " << pair.second.second <<  endl;
        for (size_t x = pair.second.first - 10; x <= pair.second.first + 10; x++) {
            for (size_t y = pair.second.second - 10; y <= pair.second.second + 10; y++) {
                png->getPixel(x, y).h = 240;
                png->getPixel(x, y).s = 1;
                png->getPixel(x, y).l = 0.5;
                png->getPixel(x, y).a = 1;
            }
        }
        drawEdges(pair);
    }

    return png;
}

void Visualizer::drawEdges(pair<StopPoint, pair<double, double>> pair) {
    vector<Edge> edges = vertexMap[pair.first.getStopID()].second;
    
    for (unsigned int i = 0; i < edges.size(); i++) {
        StopPoint destination = edges[i].getEndPoint();
        double endY = pointsMap[destination].second;
        double endX = pointsMap[destination].first;
        
        double slope = (double)(endY - pair.second.second)/ (endX - pair.second.first);
        // cout << slope << endl;
        // horizontal lines
        if (endY == pair.second.second) {
            size_t y = endY;
            // in positive direction
            if (endX > pair.second.first) {
                for (size_t x = pair.second.first; x <= endX; x++) {
                    HSLAPixel & pixel = png->getPixel(x, y);
                    pixel.h = 94;
                    pixel.s = 0.91;
                    pixel.l = 0.57;
                    pixel.a = 1;
                }
            // negative direction
            } else if (endX < pair.second.first) {
                for (size_t x = pair.second.first; x >= endX; x--) {
                    HSLAPixel & pixel = png->getPixel(x, y);
                    pixel.h = 94;
                    pixel.s = 0.91;
                    pixel.l = 0.57;
                    pixel.a = 1;
                }
            }
        // vertical lines
        } else if (endX == pair.second.first) {
            size_t x = endX;
            // postive direction
            if (endY > pair.second.second) {
                for (size_t y = pair.second.second; y <= endY; y++) {
                    HSLAPixel & pixel = png->getPixel(x, y);
                    pixel.h = 180;
                    pixel.s = 1;
                    pixel.l = 0.50;
                    pixel.a = 1;
                }
            // negative direction
            } else if (endY < pair.second.second) {
                for (size_t y = pair.second.second; y >= endY; y--) {
                    HSLAPixel & pixel = png->getPixel(x, y);
                    pixel.h = 180;
                    pixel.s = 1;
                    pixel.l = 0.50;
                    pixel.a = 1;
                }
            }
        // positive slopes in positive direction
        } else if (endX > pair.second.first && endY > pair.second.second) {
            size_t y = pair.second.second;
            size_t b = endY - (endX*slope);
            for (size_t x = pair.second.first; x <= endX; x++) {
                if (y <= endY) {
                    HSLAPixel & pixel = png->getPixel(x, y);
                    pixel.h = 318;
                    pixel.s = 0.99;
                    pixel.l = 0.5;
                    pixel.a = 1;
                    y = slope*x + b;
                }
            }
                
        // postive slopes in negative direction
        } else if (endX < pair.second.first && endY < pair.second.second) {
            size_t y = endY;
            size_t b = endY - (endX*slope);
            for (size_t x = endX; x <= pair.second.first; x++) {
                if (y <= pair.second.second) {
                    HSLAPixel & pixel = png->getPixel(x, y);
                    pixel.h = 11;
                    pixel.s = 0.84;
                    pixel.l = 0.51;
                    pixel.a = 1;
                    y = slope*x + b;
                }
            }
        // negative slopes in postive y direction
        } else if (endX > pair.second.first && endY < pair.second.second) {
            size_t y = endY;
            size_t b = endY - (endX*slope);
            for (size_t x = pair.second.first; x <= endX; x++) {
                if (y <= pair.second.second) {
                    HSLAPixel & pixel = png->getPixel(x, y);
                    pixel.h = 0;
                    pixel.s = 0;
                    pixel.l = 0;
                    pixel.a = 1;
                    y = slope*x + b;
                }
            }
        // negative slopes in negative y direction
        } else {
            size_t y = pair.second.second;
            size_t b = endY - (endX*slope);
            bool enteredLoop = false;
            for (size_t x = endX; x <= pair.second.first; x++) {
                if (y <= endY) {
                    HSLAPixel & pixel = png->getPixel(x, y);
                    pixel.h = 96;
                    pixel.s = 1;
                    pixel.l = 0.5;
                    pixel.a = 1;
                    y = slope*x + b;
                }
            }
        }
    }
}

void Visualizer::drawLine(size_t startX, size_t endX, size_t startY, size_t endY, double slope, double b, char parse) {
    if (parse == 'x') {
        size_t y = startY;
        for (size_t x = startX; x <= endX; x++) {
            if (y <= endY) {
                HSLAPixel & pixel = png->getPixel(x, y);
                pixel.h = 0;
                pixel.s = 0;
                pixel.l = 0;
                pixel.a = 1;
                y = slope*x + b;
            }
        }
    } else {
        size_t x = startX;
        for (size_t y = startY; y <= endY; y++) {
            HSLAPixel & pixel = png->getPixel(x, y);
            pixel.h = 180;
            pixel.s = 1;
            pixel.l = 0.50;
            pixel.a = 1;
        }
    }
}
#include "visualizer.h"
#include <limits.h>

using namespace std;
using namespace cs225;

void Visualizer::findOrigin() {
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
    origin = make_pair(minLon, minLat);

    // find the scale factor 
    scaleFactor.first = (double) 5000 / (maxLon - minLon);
    scaleFactor.second = (double) 5000 / (maxLat - minLat);
}

void Visualizer::calculateMinDistance() {
    double minDistance = INT_MAX;

    for (auto pair : vertexMap) {
        StopPoint stop = pair.second.first;
        double dist = sqrt(pow((stop.getStopLatitude() - origin.second), 2.0) + 
                            pow((stop.getStopLongitude() - origin.first), 2.0));

        if (dist < minDistance && dist > 0) {
            minDistance = dist;
            displacement.second = (stop.getStopLatitude() - origin.second)*scaleFactor.second;
            displacement.first = (stop.getStopLongitude() - origin.first)*scaleFactor.first;
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
    endpoint.first = ((maxLon - origin.first)*scaleFactor.first) + (1.25*displacement.first);
    endpoint.second = ((maxLat - origin.second)*scaleFactor.second) + (1.25*displacement.second);
    
    // set the locations 
    for (auto pair : vertexMap) {
        StopPoint stop = pair.second.first;
        std::pair<double, double> point;
        // flip over x axis
        point.first = ((stop.getStopLongitude() - origin.first)*scaleFactor.first) + displacement.first;
        point.second = (endpoint.second - origin.second) - (((stop.getStopLatitude() - origin.second)*scaleFactor.second) + displacement.second);
        if (stop.getStopLatitude() != 0 && stop.getStopLongitude() != 0) {
            pointsMap.insert({stop, point});
        }
    }
}

PNG* Visualizer::draw() {
    png = new PNG(endpoint.first  - origin.first, endpoint.second - origin.second);
    for (auto pair : pointsMap) {
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
        double endX = pointsMap[destination].first;
        double endY = pointsMap[destination].second;
        
        double slope = (double)(endY - pair.second.second)/ (endX - pair.second.first);

        // horizontal lines
        if (abs(endY - pair.second.second) < 5) {
            size_t y = endY;
            // in positive direction
            if (endX > pair.second.first) {
                for (size_t x = pair.second.first; x <= endX; x++) {
                    HSLAPixel & pixel = png->getPixel(x, y);
                    pixel.h = 23;
                    pixel.s = 0.95;
                    pixel.l = 0.52;
                    pixel.a = 1;
                }
            // negative direction
            } else if (endX < pair.second.first) {
                for (size_t x = pair.second.first; x >= endX; x--) {
                    HSLAPixel & pixel = png->getPixel(x, y);
                    pixel.h = 23;
                    pixel.s = 0.95;
                    pixel.l = 0.52;
                    pixel.a = 1;
                }
            }
        // vertical lines
        } else if (abs(endX - pair.second.first) < 5) {
            size_t x = endX;    
            // postive direction
            if (endY > pair.second.second) {
                for (size_t y = pair.second.second; y <= endY; y++) {
                    HSLAPixel & pixel = png->getPixel(x, y);
                    pixel.h = 23;
                    pixel.s = 0.95;
                    pixel.l = 0.52;
                    pixel.a = 1;
                }
            // negative direction
            } else if (endY < pair.second.second) {
                for (size_t y = pair.second.second; y >= endY; y--) {
                    HSLAPixel & pixel = png->getPixel(x, y);
                    pixel.h = 23;
                    pixel.s = 0.95;
                    pixel.l = 0.52;
                    pixel.a = 1;
                }
            }
        // positive slopes in positive direction
        } else if (endX > pair.second.first && endY > pair.second.second) {
            size_t x = pair.second.first;
            size_t y = pair.second.second;
            size_t b = endY - (endX*slope);
            if (slope <= 1) {
                for (; x <= endX; x++) {
                    if (y <= endY) {
                        HSLAPixel & pixel = png->getPixel(x, y);
                        pixel.h = 23;
                        pixel.s = 0.95;
                        pixel.l = 0.52;
                        pixel.a = 1;
                        y = slope*x + b;
                    }
                }
            } else {
                for (; y <= endY; y++) {
                    if (x <= endX) {
                        HSLAPixel & pixel = png->getPixel(x, y);
                        pixel.h = 23;
                        pixel.s = 0.95;
                        pixel.l = 0.52;
                        pixel.a = 1;
                        x = (y - b)/slope;
                    }
                }
            }
            
        // postive slopes in negative direction pink
        } else if (endX < pair.second.first && endY < pair.second.second) {
            size_t x = endX;
            size_t y = endY;
            size_t b = endY - (endX*slope);
            if (slope <= 1) {
                for (; x <= pair.second.first; x++) {
                    if (y <= pair.second.second) {
                        HSLAPixel & pixel = png->getPixel(x, y);
                        pixel.h = 23;
                        pixel.s = 0.95;
                        pixel.l = 0.52;
                        pixel.a = 1;
                        y = slope*x + b;
                    }
                }
            } else {
                for (; y <= pair.second.second; y++) {
                    if (x <= pair.second.second) {
                        HSLAPixel & pixel = png->getPixel(x, y);
                        pixel.h = 23;
                        pixel.s = 0.95;
                        pixel.l = 0.52;
                        pixel.a = 1;
                        x = (y - b)/slope;
                    }
                }
            }
        // negative slopes in postive y direction black
        } else if (endX > pair.second.first && endY < pair.second.second) {
            size_t x = pair.second.first;
            size_t y = pair.second.second;
            size_t b = endY - (endX*slope);
            if (abs(slope) <= 1) {
                for (; x <= endX; x++) {
                    if (y >= endY) {
                        HSLAPixel & pixel = png->getPixel(x, y);
                        pixel.h = 23;
                        pixel.s = 0.95;
                        pixel.l = 0.52;
                        pixel.a = 1;
                        y = slope*x + b;
                    }
                }
            } else {
                for (; y >= endY; y--) {
                    if (x <= endX) {
                        HSLAPixel & pixel = png->getPixel(x, y);
                        pixel.h = 23;
                        pixel.s = 0.95;
                        pixel.l = 0.52;
                        pixel.a = 1;
                        x = (y - b)/slope;
                    }
                }
            }
        // negative slopes in negative y direction black
        } else {
            size_t x = endX;
            size_t y = endY;
            size_t b = endY - (endX*slope);
            if (abs(slope) <= 1) {
                for (; x <= pair.second.first; x++) {
                    if (y >= pair.second.second) {
                        HSLAPixel & pixel = png->getPixel(x, y);
                        pixel.h = 23;
                        pixel.s = 0.95;
                        pixel.l = 0.52;
                        pixel.a = 1;
                        y = slope*x + b;
                    }
                }
            } else {
                for (; y >= pair.second.first; y--) {
                    if (x <= pair.second.first) {
                        HSLAPixel & pixel = png->getPixel(x, y);
                        pixel.h = 23;
                        pixel.s = 0.95;
                        pixel.l = 0.52;
                        pixel.a = 1;
                        x = (y - b)/slope;
                    }
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
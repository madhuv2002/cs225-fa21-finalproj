#pragma once
#include <string>
#include <map>

using namespace std;

class StopPoint {
    public:
    /**
     * Default constructor.
     */
    StopPoint();

    /**
     * StopPoint constructor.
     * @param code - the stop_code of the stop
     * @param stop_id - unique id of the stop
     * @param stop_lat - latitude of the stop
     * @param stop_lon - longitude of the stop 
     * @param stop_name - the name of the stop
     */
    StopPoint(string code, string stop_id, double stop_lat, double stop_lon, string stop_name);

    /**
     * Getter function for the ID of the stop
     */        
    string getStopID();

    /**
     * Getter function for the latitude of the stop
     */
    double getStopLatitude();

    /**
     * Getter function for the longitude of the stop
     */
    double getStopLongitude();

    /**
     * Getter function for the name of the stop
     */
    string getStopName();

    /**
     * Overloaded operator functions
     */
    bool operator <(const StopPoint& rhs) const {return stop_id_ < rhs.stop_id_;}
    bool operator==(const StopPoint& rhs) const;

    private:
    string code_;
    string stop_id_;
    double stop_lat_;
    double stop_lon_;
    string stop_name_;

};
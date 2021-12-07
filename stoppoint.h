#pragma once
#include <string>
#include <map>

using namespace std;

class StopPoint {
    public:
        StopPoint();
        StopPoint(string code, string stop_id, double stop_lat, double stop_lon, string stop_name);
        
        string getStopID();
        double getStopLatitude();
        double getStopLongitude();
        string getStopName();

        bool operator <(const StopPoint& rhs) const {return stop_id_ < rhs.stop_id_;}
        bool operator==(const StopPoint& rhs) const;

    private:
        string code_;
        string stop_id_;
        double stop_lat_;
        double stop_lon_;
        string stop_name_;

};
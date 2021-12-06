#pragma once
#include <string>
#include <map>

class StopPoint {
    public:
    StopPoint();
    StopPoint(std::string code, std::string stop_id, std::string stop_lat, std::string stop_lon, std::string stop_name);
    bool operator==(const StopPoint& rhs) const;
    std::string getStopName();
    std::string getStopID();
    double getStopLatitude();
    double getStopLongitude();

    private:
    std::string code_;
    std::string stop_id_;
    double stop_lat_;
    double stop_lon_;
    std::string stop_name_;

};
#pragma once
#include <string>
#include <map>

class StopPoint {
    public:
    StopPoint();
    StopPoint(std::string code, std::string stop_id, double stop_lat, double stop_lon, std::string stop_name);
    std::string getStopName();
    std::string getStopID();

    private:
    std::string code_;
    std::string stop_id_;
    double stop_lat_;
    double stop_lon_;
    std::string stop_name_;

};
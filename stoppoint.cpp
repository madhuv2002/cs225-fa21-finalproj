#include "stoppoint.h"
#include <string>

using namespace std;

StopPoint::StopPoint() 
    : code_(""), stop_id_(""), stop_lat_(""), stop_lon_(""), stop_name_("")
    { };

StopPoint::StopPoint(std::string code, std::string stop_id, std::string stop_lat, std::string stop_lon, std::string stop_name) 
    : code_(code), stop_id_(stop_id), stop_lat_(stop_lat), stop_lon_(stop_lon), stop_name_(stop_name)
    { };

std::string StopPoint::getStopName() {
    return stop_name_;
}

std::string StopPoint::getStopID() {
    return stop_id_;
}

bool StopPoint::operator==(const StopPoint& rhs) const {
   return code_ == rhs.code_ && stop_id_ == rhs.stop_id_ 
    && stop_lat_ == rhs.stop_lat_ && stop_lon_ == rhs.stop_lon_ 
    && stop_name_ == rhs.stop_name_; 
}
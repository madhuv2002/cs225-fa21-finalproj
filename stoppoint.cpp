#include "stoppoint.h"
#include <string>

using namespace std;

StopPoint::StopPoint() 
    : code_(""), stop_id_(""), stop_lat_(0.0), stop_lon_(0.0), stop_name_("")
    { };

StopPoint::StopPoint(string code, string stop_id, double stop_lat, double stop_lon, string stop_name) 
    : code_(code), stop_id_(stop_id), stop_lat_(stop_lat), stop_lon_(stop_lon), stop_name_(stop_name)
    { };

string StopPoint::getStopID() {
    return stop_id_;
}

double StopPoint::getStopLatitude() {
    return stop_lat_;
}

double StopPoint::getStopLongitude() {
    return stop_lon_;
}

string StopPoint::getStopName() {
    return stop_name_;
}

bool StopPoint::operator==(const StopPoint& rhs) const {
   return code_ == rhs.code_ && stop_id_ == rhs.stop_id_ 
    && stop_lat_ == rhs.stop_lat_ && stop_lon_ == rhs.stop_lon_ 
    && stop_name_ == rhs.stop_name_; 
}
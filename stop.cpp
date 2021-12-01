#include "stop.h"

Stop::Stop() 
    : stop_id(""), stop_name(""), stop_points({})
    { };

Stop::Stop(std::string stopId, std::string stopName, std::vector<StopPoint> stopPoints) 
    : stop_id(stopId), stop_name(stopName), stop_points(stopPoints)  {};
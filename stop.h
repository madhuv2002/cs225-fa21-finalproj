#pragma once
#include "stoppoint.h"
#include <string>
#include <map>
#include <vector>
using namespace std;

class Stop {
    public:
        Stop();
        Stop(std::string stopId, std::string stopName, std::vector<StopPoint> stopPoints);

    private:
        std::string stop_id;
        std::string stop_name;
        std::vector<StopPoint> stop_points;

};

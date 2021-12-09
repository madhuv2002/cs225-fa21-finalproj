## Notes 10/27
- 3 Shortest Route gives bus stops and bus names/numbers
- Try drawing the route on the graph
- Amount of time it takes
- Size of nodes could represent number of connections
## Notes 11/03
- We plan to use the following API calls:
    - GetDeparturesByStop
    - GetRoute
    - GetRoutes
    - GetRoutesByStop
    - GetShape
    - GetShapeBetweenStops
    - GetStop
    - GetStops
    - GetStopsByLatLon
    - GetStopTimesByTrip
    - GetStopTimesByStop
    - GetPlannedTripsByLatLon
    - GetPlannedTripsByStops
- We will use this repo to parse through our JSON files containing the dataset from MTD: https://github.com/nlohmann/json
- Nodes represent the stops and edges represent the routes between two subsequent stops in the graph structure.
- We would make sure that the data is valid before we use it in our functions. If we have any invalid data, we plan to omit it entirely before using it in our implementation. 
- In order to limit the number of outcomes from our implementation and have a more practical solution, we decided to cap the amount of elapsed time to walk between two stops or set a limit on the distance that the user will travel on foot.
## Notes 11/10
- Create skeleton code for the python script to convert JSON to CSV
- Make API calls to the GetStops function to understand the data and how to parse it into a more readable format
## Notes 11/17
- Started working on converting JSON files to CSV:
https://colab.research.google.com/drive/1Fo-hhbMQ18z2YYZwjAFaFTo68htAuDHC?usp=sharing
## Notes 12/01
- Finished acquiring data and uploading it to GitHub
- Finished processing vertices onto the routeMap
## Notes 12/03
- Create edge class with getters and setters 
- Begin implementation for the map of edges
## Notes 12/05
- Implement loadEdges function and edges map
- Reformat trips file that is parsed in for the edges map
## Notes 12/06
- Import the CS225 folder from previous MPS and create skeleton for Visualiser 
- Create locations for stop points in the visual 
- Calculate weights for stop points
## Notes 12/07
- Implement both the draw() and drawEdges() function




## Notes 10/27
- This week we discussed our goals for the final project and what we want to accomplish. We decided on the MTD dataset but agreed that this can be subject to change if we come up with a better idea for this project. Some of the goals we discussed were if we wanted to implement the shortest route given the bus stops or bus names/numbers, try replicating the route on the graph, and report the amount of time a bus route takes. Additionally, we discussed how the size of nodes could represent number of connections.
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
- This week we created the skeleton code for the python script to convert JSON to CSV and made API calls to the GetStops function to understand the data. This helped us understand how to parse it into a more readable format. 
## Notes 11/17
- We started working on converting JSON files to CSV:
https://colab.research.google.com/drive/1Fo-hhbMQ18z2YYZwjAFaFTo68htAuDHC?usp=sharing. We also made the MakeFile and got the skeleton code to compile. 
## Notes 12/01
- We finished acquiring data and uploaded it to GitHub. We also processed the vertices onto the routeMap. 
## Notes 12/03
- We created the edge class with getters and setters and started parsing in the edges. This took a lot more time than expected since we had to compile all the trip files into one txt file. 
## Notes 12/05
- We started working on the loadEdges function and edges map. 
- As mentioned last week, we had trouble parsing in the trips. This week we used the trips file and parsed in the edges for the edges map.
## Notes 12/06
- In order to create the visualization, we imported the CS225 folder from previous MPS and create skeleton for Visualiser. Additionally, we curated locations on the image for stop points in the visual. We also calculated the weights for stop points. This week, we started the implementation of BFS and Dijkstra's algorithm in order to find the shortest route between two bus stops. 
## Notes 12/07
- We continued working on the implementation of BFS and Dijkstra's algorithm in order to find the shortest route between two bus stops. On top of this we worked on both the draw() and drawEdges() function.
## Notes 12/11
- We finished working on the implementation of BFS and Dijkstra's algorithm and made changes to the visual. We ran into a bug where some of our edges were not drawn when the slope was really high. 
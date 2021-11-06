# MTD Bus Routing System
**Objective**:   
- Find the shortest routes and the amount of time it takes to travel between two given bus stops and create a visualization.
- This would be a general search tool that can be utilized by users of the MTD bus system. 

**Dataset Acquisition and Processing**:   
- We have chosen the MTD dataset. We will download the dataset from the MTD developer resources website, parse JSON files to .txt files and use those files for our project.
In the graph structure, nodes would represent the stops and edges represent the routes between two subsequent stops.
- We would make sure that the data is valid before we use it in our functions. If we have any invalid data, we plan to omit it entirely before using it in our implementation. 
In order to limit the number of outcomes from our implementation and have a more practical solution, we decided to cap the elapsed time to walk between two stops or set a limit on the distance that the user will travel on foot. 

**Graph Algorithms**:   
- BFS and Dijkstra’s algorithm for finding the shortest path between bus stops with weighted edges (routes).
- We will implement a graphic output of our graph which would look like an MTD map with bus stops with more connectivity represented as bigger nodes and edges with more bus routes on it would be thicker.

**Timeline**:   
- 10th November: Data acquisition and data processing
- 17th Novemeber: Make a graph
- 28th Novemeber: Implement BFS and Dijkstra's algorithm
- 1st December: Create a graph visualization
- 8th December: Finish project (review code base and organize)
- 13th December: Make any final changes, create a README.md and prepare the final presentation


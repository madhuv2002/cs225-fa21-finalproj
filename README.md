## CS225 Final Project - MTD Shortest Path
By Tina Banthia, Arnav Shah, Madhu Vakkadala

## How To Run 
Clone [this](https://github-dev.cs.illinois.edu/cs225-fa21/tinajb2-mv16-arnavss2.git) repository and cd into it. 

Run 
```
$ make
$ ./main [stopID1] [stopID2]
```
in terminal to start the program. Make sure to enter two bus stops - the start and end points of your trip. This will return the shortest list of all the routes (format: firstStopIDsecondStopIDrouteName) you would pass through to reach your destination.
You can also view our visual representation of all the MTD stops in the `map.png` file. 

To run tests, cd into the `tests` folder, and enter 
```
$ make test
$ ./test
```
in terminal to run all the tests created. It will take about 5 minutes to pass all the tests.

The data we used was taken from the https://developer.cumtd.com website. 

## Sample Outputs
```
IU:1GRNGWN:7RAVEN
GRNGWN:7CHEMLS:1RAVEN
CHEMLS:1GWNNV:4ILLINI EVENING SATURDAY
GWNNV:4GWNGRG:9ILLINI EVENING SATURDAY
GWNGRG:9GRGDNR:3RAVEN
GRGDNR:3PSL:1RAVEN
PSL:1PAR:2SILVER SATURDAY
```

## Final Project Presentation
Link: 

#include "Funcs.h"
#include <iostream>

using namespace std;
int main() {

    // Declare objects and variables
    SimulationConfig config;
    Intersection intersection;
    vector<vector<int>> trafficData;
    int selection = 0;

    string inputFilename;
    cin>> inputFilename;

    //setup phase, initilaize all the objects, loads data and allows user to make selections 
    setupSimulation(config, trafficData, inputFilename, selection);
    // runs the whole simulation, depending on user input, collects information
    runSimulation(intersection, trafficData, config);
    // displays all the collected data about the simulation
    // reportResults(intersection);
    
    return 0;
}

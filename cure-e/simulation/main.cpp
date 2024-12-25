#include "Funcs.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Declare objects and variables
    SimulationConfig config;
    Intersection intersection;
    vector<vector<int>> trafficData;
    int selection = 0;

    string inputFilename;
    cout << "Input the data file name: ";
    cin>> inputFilename;

    // Setup phase: Initialize all objects, load data, and allow user to make selections
    setupSimulation(config, trafficData, inputFilename, selection);

    // Run the simulation mode based on user selection, collect information
    runSimulationMode(intersection, trafficData, selection);

    // Display all the collected data about the simulation
    reportResults(intersection);

    return 0;
}

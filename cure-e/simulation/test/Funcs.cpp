#include "Funcs.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include <cstdlib> // For rand()

using namespace std;
// ----- class implementations -----
// need to implement classes


// ------ other helpful functions -------

//distance conversions
double convertDistance(double value, bool toMeters) {
    double feetToMeters = 0.3048;
    return toMeters ? value * feetToMeters : value / feetToMeters;
}

//speed conversions
double convertSpeed(double value, bool toMPS) {
    double milesToMeters = 1609.34;
    return toMPS ? value * (milesToMeters / 3600.0) : value * (3600.0 / milesToMeters);
}

// ----------Functions for setup()------------ complete

// reads all the data into a vector
vector<vector<int>> readInputData(string filename) {
    ifstream inFS(filename);

    vector<vector<int>> trafficData;

    int num;
    vector<int> oneDirectionData;

    while (inFS >> num) {
        oneDirectionData.push_back(num);

        if (oneDirectionData.size() == 4) {
            trafficData.push_back(oneDirectionData);
            oneDirectionData.clear(); 
        }
    }

    inFS.close();
    cout<<trafficData.size()<< endl;
    return trafficData;
    
}

// makes sure the file being opened exists
bool validateFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return false;
    }
    return true;
}

// makes sure the traffic data is in the correct format
bool validateTrafficData(const vector<vector<int>> &trafficData) {

    for (int i =0; i < trafficData.size(); i++) {

        if (trafficData[i].size() !=  4) { 
            cerr << "Error: Invalid input format. must have exactly 4 directions" << endl;
            return false;
        }
    }
    return true;
}

// user interface to select which simulation should be run

int selectSim(){
    int input;
    cout << "Select Simulation Version:"<< endl;
    cout << "[1] Default: the road without any modifications \n[2] My modificaitons: make the road as terrible as possible for cars \n[3] Sandbox mode: play with stoplight duration, car speed, etc."<< endl;
    cin >> input;
    if(input>3 || input<1){
        cout << "Invalid selection: try again:"<< endl;
        return 0;
    }
    return input;

}

// ---- setup function loads all the data, sets up the intersection object, sets random seed ---

void setup(vector<vector<int>> &trafficData, const string &filename, int &selection) {
    // seed the random number generator
    srand(time(0));
    //make sure we can load the data from the file
    if (!validateFile(filename)) {
        exit(1); 
    }

    // read traffic data from the input file
    trafficData = readInputData(filename);

    if (trafficData.empty()) {
        cerr << "Error: No data found in file " << filename << endl;
        exit(1);
    }

    // check if the input data format is right
    if (!validateTrafficData(trafficData)) {
        exit(1);
    }

    // display a summary of the input data
    cout << "Input data summary:\n";
    cout << "Total time steps: " << trafficData.size() << "\n";
    cout << "Sample random row: ";

    for (int i = 0; i < trafficData[0].size(); ++i) {
        cout << trafficData[rand()%trafficData.size()][i] << " ";
    }
    cout << "\n";

    // selects which simulation the user wants to run. 
    while(selection == 0){
        selection = selectSim();
    }
    
    cout << "Setup complete. \n";
}

// ------ functions for simulations --- 


//------- simulation implemetaions----------
void sandbox(Intersection &intersection){
    


}

void simulationDefault(Intersection &intersection){

    // NS 
    //speed limit - 35 mph
    //Red durration - 30 sec
    //green durration  - 100sec


    // EW - 30 mph 
    // red durration - 100 sec
    // green durration - 30 sec


}

void simulationModified(Intersection &intersection){

    // NS 
    // speed limit - 35 mph
    // Red durration - 60 sec
    // green durration  - 100sec
    // all way stop 30sec during school hours

    
    // EW - 30 mph 
    // red durration - 130 sec
    // green durration - 30 sec
    // all way stop 30sec during school hours 

}

void runSimulation(Intersection &intersection, const vector<vector<int>> &trafficData, int selection) {
    
    switch (selection) {
        case 1:
            cout << "Running Default Simulation...\n";
            simulationDefault(intersection);
            break;
        case 2:
            cout << "Running Modified Simulation...\n";
            simulationModified(intersection);
            break;
        case 3:
            cout << "Entering Sandbox Mode...\n";
            sandbox(intersection);
            break;
        default:
            cerr << "Error: Invalid simulation selection.\n";
            break;
    }

}


// void teardown(const Intersection &intersection) {

//     cout << "Simulation complete. Final statistics collected." << endl;

// }

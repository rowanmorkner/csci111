#ifndef FUNCS_H
#define FUNCS_H

#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

// simulation configuration class 

class SimulationConfig {
public:
    double speedLimitMph;
    int numberOfLanes;
    double acceleration;
    bool schoolHourSlowdown;
    int nsGreenDuration;
    int nsRedDuration;
    int ewGreenDuration;
    int ewRedDuration;
    int allWayStopDuration;

    void loadDefaultConfig();
    void loadModifiedConfig();
    void sandboxMenu();
};


// random distribution class

class RandomDistributions {
public:
    double generateCarSpeed(double meanMph, double stdDevMph, double speedCapMph);
    double generateCarLengthFeet(double meanFeet, double stdDevFeet);
    char generateTurningDirection();
    // Additional random generation functions as needed
};


// car class 

class Car {
private:
    int m_arrivalTime;
    int m_departTime;
    char m_turning;
    double m_speed;
    double m_maxSpeed;
    double m_acceleration;
    double m_length;
    int m_waitTime;

public:
    Car();
    void setArrivalTime(int time);
    void setDepartTime(int time);
    void setTurning(char turn);
    void setSpeed(double speed);
    void setMaxSpeed(double maxSpeed);
    void setAcceleration(double acceleration);
    void setLength(double length);
    void setWaitTime(int waitTime);
    
    int getArrivalTime() const;
    int getDepartTime() const;
    char getTurning() const;
    double getSpeed() const;
    double getMaxSpeed() const;
    double getAcceleration() const;
    double getLength() const;
    int getWaitTime() const;
    
    void initializeTurning();
};


// lane class

class Lane {
private:
    queue<Car> cars;

public:
    void addCar(const Car &newCar);
    bool hasCars() const;
    Car& getFrontCar();
    void advanceCars(bool canMove, int currentTime);
    void recordCarIfCleared();
    int getCarsWaiting() const;
};


// street class

class Street {
private:
    int greenDuration;
    int redDuration;
    bool isNSDirection;
    double speedLimitMph;
    vector<Lane> lanes;


    int totalCarsPassed;
    double totalSpeed;
    double totalWaitTime;
    vector<int> carsPassedPerHour;
    vector<double> speedPerHour;
    vector<double> waitTimePerHour;


public:
    //defaults
    Street();
    Street(int greenDuration, int redDuration, bool isNSDirection);
    //setters 
    void setLaneCount(int count);
    void setSpeedLimit(double speedLimit);
    double getSpeedLimit() const;
    void addArrivingCars(int arrivingCars, RandomDistributions &dist, bool isSchoolHour, double currentSpeedLimit);
    void updateLanes(bool canMove);
    void collectClearedCarsData(int time);
    int getTotalCarsWaiting() const;

    // getter methods
    int getTotalCarsPassed() const;
    double getAverageSpeed() const;
    double getAverageWaitTime() const;
    
    int getTotalCarsPassedPerHour(int hour) const;
    double getAverageSpeedPerHour(int hour) const;
    double getAverageWaitTimePerHour(int hour) const;
};


// traffic light class

class TrafficLightController {
private:
    bool isNSGreen;
    bool isEWGreen;
    bool allWayStopActive;
    int timeInCurrentPhase;
    int nsGreenDuration;
    int nsRedDuration;
    int ewGreenDuration;
    int ewRedDuration;
    int allWayStopDuration;

public:
    TrafficLightController();
    void setDurations(const SimulationConfig &config);
    void update(int currentTime);
    bool isNorthSouthGreen() const;
    bool isEastWestGreen() const;
    bool isAllWayStopActive() const;
};


// intersection class

class Intersection {
private:
    Street northStreet;
    Street southStreet;
    Street eastStreet;
    Street westStreet;
    TrafficLightController trafficLights;
    RandomDistributions distributions;
    SimulationConfig currentConfig; 

public:
    // setters

    Intersection();
    void configure(const SimulationConfig &config);
    void addCarsFromInput(int time, const vector<int> &arrivals);
    void updateTrafficLights(int currentTime);
    void updateCarMovements(int currentTime);
    void recordStatistics(int time);
    void finalizeStatistics();
    
    bool isSchoolHour(int currentTime) const;

    // getters
    const SimulationConfig& getConfig() const;
    int getTotalCarsNorth() const;
    int getTotalCarsSouth() const;
    int getTotalCarsEast() const;
    int getTotalCarsWest() const;
    double getAverageSpeed() const;
    double getAverageWaitTime() const;
    
    int getTotalCarsNorthPerHour(int hour) const;
    int getTotalCarsSouthPerHour(int hour) const;
    int getTotalCarsEastPerHour(int hour) const;
    int getTotalCarsWestPerHour(int hour) const;
    double getAverageSpeedPerHour(int hour) const;
    double getAverageWaitTimePerHour(int hour) const;
};


// stats class 

class Statistics {
private:
    int totalCarsNorth;
    int totalCarsSouth;
    int totalCarsEast;
    int totalCarsWest;
    double averageSpeed;
    double averageWaitTime;

public:
    Statistics(); 
    void compute(const Street &north, const Street &south, const Street &east, const Street &west);
    void report() const;
};


// Standalone Functions

// checks if file is in directory
bool validateFile(string filename);
//reads input data into vecor of vectors
vector<vector<int>> readInputData(string filename);
// makes sure data is correctly formatted 
bool validateTrafficData(const vector<vector<int>> &trafficData);
// simulation selection menu
int selectSimulationMode();

//main funcitons to run the entire simulation 
void setupSimulation(SimulationConfig &config, vector<vector<int>> &trafficData, const string &filename, int &modeSelection);
void runSimulation(Intersection &intersection, const vector<vector<int>> &trafficData, const SimulationConfig &config);
void reportResults(const Intersection &intersection);

// funcitons that implement the specific simulation depending on all of the modifications to the intersection class

void sandbox(Intersection &intersection);
void simulationDefault(Intersection &intersection);
void simulationModified(Intersection &intersection);
void runSimulationMode(Intersection &intersection, const vector<vector<int>> &trafficData, int selection);

#endif

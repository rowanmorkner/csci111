#ifndef FUNCS_H
#define FUNCS_H

#include <queue>
#include <vector>
#include <string>

using namespace std;

// Car class declaration
class Car {
private:
    int m_arrivalTime = 0;
    int m_departTime = -1;
    char m_turning = 'S'; // Turning direction: 'L' 'R' 'S' - left right straint
    double m_speed = 15.6464; //meters per second
    double m_acceleration = 6; // miles/second^2  assuming the car goes from 0 - 60 in 10 seconds. 
    int m_waitTime; = 0;

public:
    Car();
    void setTurning(char turn);
    void setSpeed(double speed);
    void setWaitTime(int waitTime);
    void setArrivalTime(int time);
    void setDepartTime(int time);
    void setRandomTurning();

    char getTurning() const;
    double getSpeed() const;
    double getAcceleration() const;
    int getWaitTime() const;
    int getArrivalTime() const;
    int getDepartTime() const;
};

// Street class declaration
class Street {
private:
    bool m_lightStatus;         // true = GREEN, false = RED
    queue<Car> m_waitingCars;   // Queue of cars waiting
    int m_greenDuration;
    int m_redDuration;
    int m_timeInCurrentPhase;

public:
    Street(int greenDuration, int redDuration);
    void updateLightState();
    void addCar(const Car &newCar);
    bool removeCar();

    bool isGreen() const;
    int getCarsWaiting() const;
};


// Intersection class declaration
class Intersection {
private:
    vector<Street> streets; // Four streets for N, S, E, W

public:
    Intersection();
    void updateSignals();
    void configureStreets();
    void addCarsToStreets(const vector<int> &arrivals);
    void processIntersection();
    int getTotalWaitingCars() const;
};

// Function prototypes

// reads traffic data from the input file and organizes it into a vector of vectors
vector<vector<int>> readInputData(string filename);

// checks if the file exists and can be opened
bool validateFile(string filename);

// validates that traffic data is correctly formatted with exactly 4 directions per row
bool validateTrafficData(const vector<vector<int>> &trafficData);

// provides a user interface for selecting the simulation version to run
int selectSim();

// sets up the simulation by loading data, validating inputs, and initializing the simulation mode
void setup(Intersection intersection,vector<vector<int>> &trafficData, const string &filename, int &selection);

void runSimulation(Intersection &intersection, const vector<vector<int> > &trafficData);
// void teardown(const Intersection &intersection);

#endif 

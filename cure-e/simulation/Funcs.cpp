#include "Funcs.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <queue>

using namespace std;

// initialize random number generator
static mt19937 generator(time(0));

// Converts speed between mph and meters per second
double convertSpeed(double speed, bool toMetersPerSecond) {
    if(toMetersPerSecond) {
        return speed * 0.44704; // 1 mph = 0.44704 m/s
    } else {
        return speed / 0.44704; // 1 m/s = 2.23694 mph
    }
}

// Converts distance between feet and meters
double convertDistance(double distance, bool toMeters) {
    if(toMeters) {
        return distance * 0.3048; // 1 foot = 0.3048 meters
    } else {
        return distance / 0.3048; // 1 meter = 3.28084 feet
    }
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

// ------------- simulation class implementation ----------------
// these are the assumed paraameters for the road, they are based on a basic google search
void SimulationConfig::loadDefaultConfig() {
    speedLimitMph = 35;
    numberOfLanes = 2;
    acceleration = 2.68;
    schoolHourSlowdown = false;
    nsGreenDuration = 100;
    nsRedDuration = 30;
    ewGreenDuration = 30;
    ewRedDuration = 100;
    allWayStopDuration = 0;
}
// this is the version where i reduce the speed limit, slow everyone down during school hours, and add an alway stop
void SimulationConfig::loadModifiedConfig() {
    speedLimitMph = 25;
    numberOfLanes = 2;
    acceleration = 2.68;
    schoolHourSlowdown = true;
    nsGreenDuration = 100;
    nsRedDuration = 60;
    ewGreenDuration = 30;
    ewRedDuration = 130;
    allWayStopDuration = 30;
}

// this allows the user to simulate all kinds of intersection configurations it works but some configs like increasing the speed limit and number of lanes results in some unexpected outcomes like worse traffic flow.

void SimulationConfig::sandboxMenu() {
    int choice = 0;
    while (choice != -1) {
        cout << "\nSandbox Menu:\n";
        cout << "1. Speed limit: " << speedLimitMph << " mph\n";
        cout << "2. Number of lanes: " << numberOfLanes << "\n";
        cout << "3. Acceleration: " << acceleration << " m/s^2\n";
        cout << "4. Enable school-hour slowdown: " << (schoolHourSlowdown ? "Yes" : "No") << "\n";
        cout << "5. North-South green duration: " << nsGreenDuration << " s\n";
        cout << "6. North-South red duration: " << nsRedDuration << " s\n";
        cout << "7. East-West green duration: " << ewGreenDuration << " s\n";
        cout << "8. East-West red duration: " << ewRedDuration << " s\n";
        cout << "9. All-way stop duration: " << allWayStopDuration << " s\n";
        cout << "Enter the number of the parameter you want to change (-1 to exit): ";
        cin >> choice;

        switch(choice) {
            case 1: {
                double newSpeed;
                cout << "Enter new speed limit (5-200 mph): ";
                cin >> newSpeed;
                if (newSpeed >= 5 && newSpeed <= 200) {
                    speedLimitMph = newSpeed;
                    cout << "Speed limit updated to " << speedLimitMph << " mph.\n";
                } else {
                    cout << "Invalid speed limit. Must be between 5 and 200 mph.\n";
                }
                break;
            }
            case 2: {
                int newLanes;
                cout << "Enter new number of lanes (1-15): ";
                cin >> newLanes;
                if (newLanes >=1 && newLanes <=15) {
                    numberOfLanes = newLanes;
                    cout << "Number of lanes updated to " << numberOfLanes << ".\n";
                } else {
                    cout << "Invalid number of lanes. Must be between 1 and 15.\n";
                }
                break;
            }
            case 3: {
                double newAcc;
                cout << "Enter new acceleration (m/s^2): ";
                cin >> newAcc;
                if (newAcc >0) {
                    acceleration = newAcc;
                    cout << "Acceleration updated to " << acceleration << " m/s^2.\n";
                } else {
                    cout << "Invalid acceleration. Must be positive.\n";
                }
                break;
            }
            case 4: {
                char enable;
                cout << "Enable school-hour slowdown? (y/n): ";
                cin >> enable;
                if (enable == 'y' || enable == 'Y') {
                    schoolHourSlowdown = true;
                    cout << "School-hour slowdown enabled.\n";
                } else if (enable == 'n' || enable == 'N') {
                    schoolHourSlowdown = false;
                    cout << "School-hour slowdown disabled.\n";
                } else {
                    cout << "Invalid input. Please enter 'y' or 'n'.\n";
                }
                break;
            }
            case 5: {
                int newDur;
                cout << "Enter new North-South green duration (1-900 s): ";
                cin >> newDur;
                if (newDur >=1 && newDur <=900) {
                    nsGreenDuration = newDur;
                    cout << "North-South green duration updated to " << nsGreenDuration << " seconds.\n";
                } else {
                    cout << "Invalid duration. Must be between 1 and 900 seconds.\n";
                }
                break;
            }
            case 6: {
                int newDur;
                cout << "Enter new North-South red duration (1-900 s): ";
                cin >> newDur;
                if (newDur >=1 && newDur <=900) {
                    nsRedDuration = newDur;
                    cout << "North-South red duration updated to " << nsRedDuration << " seconds.\n";
                } else {
                    cout << "Invalid duration. Must be between 1 and 900 seconds.\n";
                }
                break;
            }
            case 7: {
                int newDur;
                cout << "Enter new East-West green duration (1-900 s): ";
                cin >> newDur;
                if (newDur >=1 && newDur <=900) {
                    ewGreenDuration = newDur;
                    cout << "East-West green duration updated to " << ewGreenDuration << " seconds.\n";
                } else {
                    cout << "Invalid duration. Must be between 1 and 900 seconds.\n";
                }
                break;
            }
            case 8: {
                int newDur;
                cout << "Enter new East-West red duration (1-900 s): ";
                cin >> newDur;
                if (newDur >=1 && newDur <=900) {
                    ewRedDuration = newDur;
                    cout << "East-West red duration updated to " << ewRedDuration << " seconds.\n";
                } else {
                    cout << "Invalid duration. Must be between 1 and 900 seconds.\n";
                }
                break;
            }
            case 9: {
                int newDur;
                cout << "Enter new all-way stop duration (1-900 s): ";
                cin >> newDur;
                if (newDur >=1 && newDur <=900) {
                    allWayStopDuration = newDur;
                    cout << "All-way stop duration updated to " << allWayStopDuration << " seconds.\n";
                } else {
                    cout << "Invalid duration. Must be between 1 and 900 seconds.\n";
                }
                break;
            }
            case -1:
                cout << "Exiting sandbox menu.\n";
                break;
            default:
                cout << "Invalid selection. Please choose a valid option.\n";
                break;
        }
    }
}

// ------ random distribution class implementation ------ //

double drawPositiveNormal(double mean, double stdDev) {
    normal_distribution<double> distribution(mean, stdDev);
    double value;
    do {
        value = distribution(generator);
    } while (value <= 0);
    return value;
}

double RandomDistributions::generateCarSpeed(double meanMph, double stdDevMph, double speedCapMph) {
    double speedMph = drawPositiveNormal(meanMph, stdDevMph);
    if (speedMph > speedCapMph) {
        speedMph = speedCapMph;
    }
    double speedMps = convertSpeed(speedMph, true);
    return speedMps;
}

double RandomDistributions::generateCarLengthFeet(double meanFeet, double stdDevFeet) {
    double lengthFeet = drawPositiveNormal(meanFeet, stdDevFeet);
    double lengthMeters = convertDistance(lengthFeet, true);

    return lengthMeters;
}

char RandomDistributions::generateTurningDirection() {
    uniform_real_distribution<double> distribution(0.0, 1.0);
    double randVal = distribution(generator);
    if (randVal < (1.0 / 3.0)) {
        return 'L';
    }
    else if (randVal < (2.0 / 3.0)) {
        return 'S';
    }
    else {
        return 'R';
    }
}

// ------- Car Class Implementation ---------------------
Car::Car() {
    m_arrivalTime = 0;
    m_departTime = -1;
    m_turning = 'S';
    m_speed = 15.6464;
    m_maxSpeed = 35; // Default max speed, can be set later
    m_acceleration = 2.68;
    m_length = 4.5; // Default length in meters
    m_waitTime = 0;
}

void Car::setArrivalTime(int time) {
    m_arrivalTime = time;
}

void Car::setDepartTime(int time) {
    m_departTime = time;
}

void Car::setTurning(char turn) {
    m_turning = turn;
}

void Car::setSpeed(double speed) {
    m_speed = speed;
}

void Car::setMaxSpeed(double maxSpeed) {
    m_maxSpeed = maxSpeed;
}

void Car::setAcceleration(double acceleration) {
    m_acceleration = acceleration;
}

void Car::setLength(double length) {

    m_length = convertDistance(length, true);
}

void Car::setWaitTime(int waitTime) {
    m_waitTime = waitTime;
}

int Car::getArrivalTime() const {
    return m_arrivalTime;
}

int Car::getDepartTime() const {
    return m_departTime;
}

char Car::getTurning() const {
    return m_turning;
}

double Car::getSpeed() const {
    return m_speed;
}

double Car::getMaxSpeed() const {
    return m_maxSpeed;
}

double Car::getAcceleration() const {
    return m_acceleration;
}

double Car::getLength() const {
    return m_length;
}

int Car::getWaitTime() const {
    return m_waitTime;
}

void Car::initializeTurning() {
    RandomDistributions rd;
    m_turning = rd.generateTurningDirection();
}

// ------------ lane class implementation ------

void Lane::addCar(const Car &newCar) {
    cars.push(newCar);
}

bool Lane::hasCars() const {
    return !cars.empty();
}

Car& Lane::getFrontCar() {
    return cars.front();
}

// needs review doesn't actually work the way i want it to

void Lane::advanceCars(bool canMove, int currentTime) {
    if (hasCars()) {
        Car& frontCar = getFrontCar();
        
        if (canMove) {
            double currentSpeed = frontCar.getSpeed();
            double maxSpeed = frontCar.getMaxSpeed();
            double accelerationRate = frontCar.getAcceleration();
            
            if (currentSpeed < maxSpeed) {
                currentSpeed += accelerationRate * 1.0; 
                if (currentSpeed > maxSpeed) {
                    currentSpeed = maxSpeed;
                }
                frontCar.setSpeed(currentSpeed);
            }
            
            frontCar.setWaitTime(frontCar.getWaitTime() + 1);
            
        }
        else {

            if(frontCar.getSpeed() > 0.0) {
                frontCar.setSpeed(0.0);
            }
            
            frontCar.setWaitTime(frontCar.getWaitTime() + 1);
        }
    }
}


void Lane::recordCarIfCleared() {
    if (hasCars()) {
        Car frontCar = getFrontCar();
        if (frontCar.getSpeed() > 0) {
            cars.pop();
        }
    }
}

int Lane::getCarsWaiting() const {
    return static_cast<int>(cars.size());
}

// ---------------- street class implementation -------------------------
Street::Street() {
    greenDuration = 0;
    redDuration = 0;
    isNSDirection = true;

    speedLimitMph = 35;
    totalCarsPassed = 0;
    totalSpeed = 0.0;
    totalWaitTime = 0.0;

    carsPassedPerHour = std::vector<int>(24, 0);
    speedPerHour = std::vector<double>(24, 0.0);
    waitTimePerHour = std::vector<double>(24, 0.0);
}

Street::Street(int greenDuration, int redDuration, bool isNSDirection) {
    this->greenDuration = greenDuration;
    this->redDuration = redDuration;
    this->isNSDirection = isNSDirection;

    speedLimitMph = 35;
    totalCarsPassed = 0;
    totalSpeed = 0.0;
    totalWaitTime = 0.0;

    carsPassedPerHour = std::vector<int>(24, 0);
    speedPerHour = std::vector<double>(24, 0.0);
    waitTimePerHour = std::vector<double>(24, 0.0);
}


void Street::setLaneCount(int count) {
    lanes.clear();
    for(int i = 0; i < count; i++) {
        lanes.push_back(Lane()); 
    }
}

void Street::setSpeedLimit(double speedLimit) {
    speedLimitMph = speedLimit;
}

double Street::getSpeedLimit() const {
    return speedLimitMph;
}

void Street::addArrivingCars(int arrivingCars, RandomDistributions &dist, bool isSchoolHour, double currentSpeedLimit) {
    
    for(int i = 0; i < arrivingCars; i++) {
        Car car;
        // we assume that everyones speed is drawn from a random distibution centered around the speed limit plus 7mph
        double meanSpeed = currentSpeedLimit + 7 ;
        double speed = dist.generateCarSpeed(meanSpeed, 3, currentSpeedLimit);
        car.setSpeed(speed);
        // and the length of the car is drawn from a normal distribution 
        double length = dist.generateCarLengthFeet(14.7, 2);
        car.setLength(length);

        car.setAcceleration(2.68);
        car.setMaxSpeed(currentSpeedLimit);
        
        if(!isNSDirection) {
            char turn = dist.generateTurningDirection();
            car.setTurning(turn);
        }
        else {
            car.setTurning('S');
        }

        // if the car is turning we need to put it in the correct lane
        int laneIndex = 0;
        if(car.getTurning() == 'L') {
            laneIndex = lanes.size() - 1;
        }
        // the car defaults to being in the right lane represented
        else if(car.getTurning() == 'R') {
            laneIndex = 0;
        }
        // if there are multiple cars in a lane already the car will choose another lane
        else {
            int minCars = lanes[0].getCarsWaiting();
            laneIndex = 0;
            for(int j = 1; j < lanes.size(); j++) {
                if(lanes[j].getCarsWaiting() < minCars) {
                    minCars = lanes[j].getCarsWaiting();
                    laneIndex = j;
                }
            }
            for(int j = 0; j < lanes.size(); j++) {
                if(lanes[j].getCarsWaiting() < lanes[laneIndex].getCarsWaiting() - 1) {
                    laneIndex = j;
                    break;
                }
            }
        }
        
        lanes[laneIndex].addCar(car);
    }
}

void Street::updateLanes(bool canMove) {
    for (int i = 0; i < lanes.size(); ++i) {
        lanes[i].advanceCars(canMove, 0);
    }
}

void Street::collectClearedCarsData(int time) {

    int hour = time / 3600; 
    for (int i = 0; i < lanes.size(); ++i) {
        if (lanes[i].hasCars()) {
            Car &car = lanes[i].getFrontCar();
            if (car.getSpeed() > 0) {
                // Update total cars passed
                totalCarsPassed++;
                totalSpeed += car.getSpeed();
                totalWaitTime += car.getWaitTime();

                // Update hourly statistics
                carsPassedPerHour[hour]++;
                speedPerHour[hour] += car.getSpeed();
                waitTimePerHour[hour] += car.getWaitTime();

                // Clear the car from the lane
                lanes[i].recordCarIfCleared();
            }
        }
    }
}

int Street::getTotalCarsPassed() const {
    return totalCarsPassed;
}

double Street::getAverageSpeed() const {
    if(totalCarsPassed == 0) return 0.0;
    return totalSpeed / totalCarsPassed;
}

double Street::getAverageWaitTime() const {
    if(totalCarsPassed == 0) return 0.0;
    return totalWaitTime / totalCarsPassed;
}

int Street::getTotalCarsPassedPerHour(int hour) const {
    if(hour < 0 || hour >= 24) return 0;
    return carsPassedPerHour[hour];
}

double Street::getAverageSpeedPerHour(int hour) const {
    if(hour < 0 || hour >= 24 || carsPassedPerHour[hour] == 0) return 0.0;
    return speedPerHour[hour] / carsPassedPerHour[hour];
}

double Street::getAverageWaitTimePerHour(int hour) const {
    if(hour < 0 || hour >= 24 || carsPassedPerHour[hour] == 0) return 0.0;
    return waitTimePerHour[hour] / carsPassedPerHour[hour];
}

// ---------------traffic light class implementation ---------------

TrafficLightController::TrafficLightController() {
    isNSGreen = true;
    isEWGreen = false;
    allWayStopActive = false;
    timeInCurrentPhase = 0;
    nsGreenDuration = 100;
    nsRedDuration = 30;
    ewGreenDuration = 30;
    ewRedDuration = 100;
    allWayStopDuration = 30;
}


void TrafficLightController::setDurations(const SimulationConfig &config) {
    nsGreenDuration = config.nsGreenDuration;
    nsRedDuration = config.nsRedDuration;
    ewGreenDuration = config.ewGreenDuration;
    ewRedDuration = config.ewRedDuration;
    allWayStopDuration = config.allWayStopDuration;
}


void TrafficLightController::update(int currentTime) {
    if (allWayStopActive) {
        if (timeInCurrentPhase >= allWayStopDuration) {
            allWayStopActive = false;
            isNSGreen = true;
            isEWGreen = false;
            timeInCurrentPhase = 0;
        }
        else {
            timeInCurrentPhase++;
        }
        return;
    }

    timeInCurrentPhase++;

    if (isNSGreen && timeInCurrentPhase >= nsGreenDuration) {
        isNSGreen = false;
        isEWGreen = true;
        timeInCurrentPhase = 0;
    }

    else if (isEWGreen && timeInCurrentPhase >= ewGreenDuration) {
        isEWGreen = false;
        isNSGreen = true;
        timeInCurrentPhase = 0;
    }

    // Trigger all-way stop during specific times (school-hour periods)
    
    if ((currentTime == 7 * 3600 + 45 * 60) ||
        (currentTime == 12 * 3600 + 10 * 60) ||
        (currentTime == 15 * 3600 + 10 * 60)) {
        allWayStopActive = true;
        isNSGreen = false;
        isEWGreen = false;
        timeInCurrentPhase = 0;
    }
}

bool TrafficLightController::isNorthSouthGreen() const {
    return isNSGreen;
}

bool TrafficLightController::isEastWestGreen() const {
    return isEWGreen;
}

bool TrafficLightController::isAllWayStopActive() const {
    return allWayStopActive;
}

// ---------------------- intersection class implementation ------
Intersection::Intersection() {
    northStreet = Street(100, 30, true);
    southStreet = Street(100, 30, true);
    eastStreet = Street(30, 100, false);
    westStreet = Street(30, 100, false);
    trafficLights = TrafficLightController();
    distributions = RandomDistributions();
    currentConfig = SimulationConfig(); 
}

void Intersection::configure(const SimulationConfig &config) {
    currentConfig = config; 

    northStreet.setLaneCount(config.numberOfLanes);
    southStreet.setLaneCount(config.numberOfLanes);
    eastStreet.setLaneCount(config.numberOfLanes);
    westStreet.setLaneCount(config.numberOfLanes);

    trafficLights.setDurations(config);

    northStreet.setSpeedLimit(config.speedLimitMph);
    southStreet.setSpeedLimit(config.speedLimitMph);
    eastStreet.setSpeedLimit(config.speedLimitMph);
    westStreet.setSpeedLimit(config.speedLimitMph);
}

void Intersection::addCarsFromInput(int time, const vector<int> &arrivals) {
    // make sure it has 4 elements n,s,e,w
    if(arrivals.size() != 4) {
        cerr << "Error: Arrivals vector must have exactly 4 elements.\n";
        return;
    }

    northStreet.addArrivingCars(arrivals[2], distributions, isSchoolHour(time), northStreet.getSpeedLimit());
    southStreet.addArrivingCars(arrivals[3], distributions, isSchoolHour(time), southStreet.getSpeedLimit());
    eastStreet.addArrivingCars(arrivals[0], distributions, isSchoolHour(time), eastStreet.getSpeedLimit());
    westStreet.addArrivingCars(arrivals[1], distributions, isSchoolHour(time), westStreet.getSpeedLimit());
}

void Intersection::updateTrafficLights(int currentTime) {
    trafficLights.update(currentTime);
}

void Intersection::updateCarMovements(int currentTime) {
    bool nsCanMove = trafficLights.isNorthSouthGreen() && !trafficLights.isAllWayStopActive();
    bool ewCanMove = trafficLights.isEastWestGreen() && !trafficLights.isAllWayStopActive();

    // if the direction has green light it will call update lanees and advance the cars through the intersection
    northStreet.updateLanes(nsCanMove);
    southStreet.updateLanes(nsCanMove);
    eastStreet.updateLanes(ewCanMove);
    westStreet.updateLanes(ewCanMove);
}

void Intersection::recordStatistics(int time) {
    northStreet.collectClearedCarsData(time);
    southStreet.collectClearedCarsData(time);
    eastStreet.collectClearedCarsData(time);
    westStreet.collectClearedCarsData(time);
}

void Intersection::finalizeStatistics() {
    // Implement actual statistics computation and reporting
    Statistics stats;
    stats.compute(northStreet, southStreet, eastStreet, westStreet);
    stats.report();
}

// this is the main modification I make for the project, changing the speeds during school time
bool Intersection::isSchoolHour(int currentTime) const {
    
    // 7:45 - 8:15
    // 12:10 - 12:30
    // 15:10 - 15:30

// i define school hour periods in seconds since midnight
    int periods[][2] = {
        {7 * 3600 + 45 * 60, 8 * 3600 + 15 * 60},
        {12 * 3600 + 10 * 60, 12 * 3600 + 30 * 60},
        {15 * 3600 + 10 * 60, 15 * 3600 + 30 * 60}
    };

    int numPeriods = sizeof(periods) / sizeof(periods[0]);

    for(int i = 0; i < numPeriods; i++) {
        if(currentTime >= periods[i][0] && currentTime <= periods[i][1]) {
            return true;
        }
    }
    return false;
}

const SimulationConfig& Intersection::getConfig() const { 
    return currentConfig; 
}

// these methods collect data on how many cars are passing though the intersecion and other important info
int Intersection::getTotalCarsNorth() const { 
    return northStreet.getTotalCarsPassed(); 
}

int Intersection::getTotalCarsSouth() const { 
    return southStreet.getTotalCarsPassed(); 
}

int Intersection::getTotalCarsEast() const { 
    return eastStreet.getTotalCarsPassed(); 
}

int Intersection::getTotalCarsWest() const { 
    return westStreet.getTotalCarsPassed(); 
}

double Intersection::getAverageSpeed() const { 
    return (northStreet.getAverageSpeed() + southStreet.getAverageSpeed() + eastStreet.getAverageSpeed() + westStreet.getAverageSpeed()) / 4.0;
}

double Intersection::getAverageWaitTime() const { 
    return (northStreet.getAverageWaitTime() + southStreet.getAverageWaitTime() + eastStreet.getAverageWaitTime() + westStreet.getAverageWaitTime()) / 4.0;
}

double Intersection::getAverageSpeedPerHour(int hour) const { 
    return (northStreet.getAverageSpeedPerHour(hour) + southStreet.getAverageSpeedPerHour(hour) + eastStreet.getAverageSpeedPerHour(hour) + westStreet.getAverageSpeedPerHour(hour)) / 4.0;
}

int Intersection::getTotalCarsNorthPerHour(int hour) const { 
    return northStreet.getTotalCarsPassedPerHour(hour); 
}

int Intersection::getTotalCarsSouthPerHour(int hour) const { 
    return southStreet.getTotalCarsPassedPerHour(hour); 
}

int Intersection::getTotalCarsEastPerHour(int hour) const { 
    return eastStreet.getTotalCarsPassedPerHour(hour); 
}

int Intersection::getTotalCarsWestPerHour(int hour) const { 
    return westStreet.getTotalCarsPassedPerHour(hour); 
}

double Intersection::getAverageWaitTimePerHour(int hour) const { 
    return (northStreet.getAverageWaitTimePerHour(hour) + southStreet.getAverageWaitTimePerHour(hour) +
            eastStreet.getAverageWaitTimePerHour(hour) + westStreet.getAverageWaitTimePerHour(hour)) / 4.0;
}

// ------- stats class implementation -----
// default constructor for stats 
Statistics::Statistics() {
    totalCarsNorth = 0;
    totalCarsSouth = 0;
    totalCarsEast = 0;
    totalCarsWest = 0;
    averageSpeed = 0.0;
    averageWaitTime = 0.0;

}

// Compute method: Aggregate data from Street instances
void Statistics::compute(const Street &north, const Street &south, const Street &east, const Street &west) {
    // Aggregate total cars passed
    totalCarsNorth = north.getTotalCarsPassed();
    totalCarsSouth = south.getTotalCarsPassed();
    totalCarsEast = east.getTotalCarsPassed();
    totalCarsWest = west.getTotalCarsPassed();

    // Calculate average speed
    averageSpeed = (north.getAverageSpeed() + south.getAverageSpeed() +
                   east.getAverageSpeed() + west.getAverageSpeed()) / 4.0;

    // Calculate average wait time
    averageWaitTime = (north.getAverageWaitTime() + south.getAverageWaitTime() +
                       east.getAverageWaitTime() + west.getAverageWaitTime()) / 4.0;
}

// display the computed statistics
void Statistics::report() const {
    cout << "\n--- Simulation Statistics ---\n";
    cout << "Total Cars Passed North: " << totalCarsNorth << endl;
    cout << "Total Cars Passed South: " << totalCarsSouth << endl;
    cout << "Total Cars Passed East: " << totalCarsEast << endl;
    cout << "Total Cars Passed West: " << totalCarsWest << endl;
    cout << "Average Speed Overall: " << averageSpeed << " m/s\n";
    cout << "Average Wait Time Overall: " << averageWaitTime << " seconds\n";
    // Add more detailed reports as needed
}

// user interface to select which type of simulation they want to run
int selectSimulationMode() {
    int input;
    cout << "\nSelect Simulation Version:" << endl;
    cout << "[1] Default: The road without any modifications" << endl;
    cout << "[2] Modified: Make the road as terrible as possible for cars" << endl;
    cout << "[3] Sandbox mode: Play with stoplight duration, car speed, etc." << endl;
    cout << "Enter your selection (1-3): ";
    cin >> input;
    
    if(cin.fail()) { // Handle non-integer input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input type. Please enter a number between 1 and 3.\n";
        return 0;
    }

    if (input > 3 || input < 1) {
        cout << "Invalid selection: try again.\n";
        return 0;
    }
    return input;
}

void setupSimulation(SimulationConfig &config, vector<vector<int>> &trafficData, const string &filename, int &modeSelection) {

    // validate the input file
    if (!validateFile(filename)) {
        exit(1);
    }

    // read traffic data from the file
    trafficData = readInputData(filename);

    // check if traffic data is empty
    if (trafficData.empty()) {
        cerr << "Error: No data found in file " << filename << endl;
        exit(1);
    }

    // Validate traffic data format
    if (!validateTrafficData(trafficData)) {
        exit(1);
    }

    //  tell user to select simulation mode
    while (modeSelection == 0) {
        modeSelection = selectSimulationMode();
    }

    cout << "Setup complete.\n";
}

/// run the simulation 
void runSimulation(Intersection &intersection, const vector<vector<int>> &trafficData, const SimulationConfig &config) {
    intersection.configure(config);
    for(int time = 0; time < 86400; ++time){
        if(time < trafficData.size()){
            intersection.addCarsFromInput(time, trafficData[time]);
        }
        intersection.updateTrafficLights(time);
        intersection.updateCarMovements(time);
        intersection.recordStatistics(time);
    }
    intersection.finalizeStatistics();
}


void reportResults(const Intersection &intersection) {

    cout << "would you like to view hour by hour breakdown (y/n)"<< endl;
    char input;
    cin >> input;
    if(input == 'y'){
        for(int hour = 0; hour < 24; ++hour){
            cout << "\nHour " << hour << ":\n";
            cout << "  Total cars passed North: " << intersection.getTotalCarsNorthPerHour(hour) << endl;
            cout << "  Total cars passed South: " << intersection.getTotalCarsSouthPerHour(hour) << endl;
            cout << "  Total cars passed East: " << intersection.getTotalCarsEastPerHour(hour) << endl;
            cout << "  Total cars passed West: " << intersection.getTotalCarsWestPerHour(hour) << endl;
            cout << "  Average speed: " << intersection.getAverageSpeedPerHour(hour) << " m/s\n";
            cout << "  Average wait time: " << intersection.getAverageWaitTimePerHour(hour) << " seconds\n";
        }
    }
}

// ----- simulation mode implementaions -----
void sandbox(Intersection &intersection) {
    SimulationConfig config;
    config.loadDefaultConfig();
    config.sandboxMenu();
    intersection.configure(config);
}

void simulationDefault(Intersection &intersection) {
    SimulationConfig config;
    config.loadDefaultConfig();
    intersection.configure(config);
}

void simulationModified(Intersection &intersection) {
    SimulationConfig config;
    config.loadModifiedConfig();
    intersection.configure(config);
}

// run the simulations
void runSimulationMode(Intersection &intersection, const vector<vector<int>> &trafficData, int selection) {
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

    runSimulation(intersection, trafficData, intersection.getConfig());
}

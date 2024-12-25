#include <iostream>
using namespace std;
int main() {
// Fake data for demonstration purposes.
// Data, separated by selected time interval, would be best kept in a text file
// Either read all data into a vector/array or read a line when processing each
interval
// Input data (daily traffic) should be consistent between simulation, meaning,
// the same data, spread out in the same way, should be used for both
int northArrive[15] = {2, 1, 3, 0, 1, 1, 2, 0, 3, 1, 0, 3, 2, 1, 2};
int southArrive[15] = {0, 3, 2, 1, 3, 2, 0, 1, 3, 0, 2, 1, 0, 3, 2};
int westArrive[15] = {1, 2, 0, 3, 1, 2, 0, 1, 3, 0, 2, 3, 1, 2, 0};
int eastArrive[15] = {2, 0, 3, 1, 2, 3, 0, 1, 2, 0, 3, 1, 2, 3, 0};
// Variable used to represent cars waiting at the intersection
int northWaiting = 0;
int southWaiting = 0;
int westWaiting = 0;
int eastWaiting = 0;
// Variable used to represent the stop light
// True means green for N/S, red for E/W
// False means red for N/S, green for E/W
bool light = true;

    for(int i =0; i< 15; i++){
        //cars arrive
        northWaiting += northArrive[i];
        southWaiting += southArrive[i];
        westWaiting += westArrive[i];
        eastWaiting += eastWaiting[i];
        //light changes
        if(i % 6 == 0){
            light = !light;
        }
        //cars leave
        if(light == true){
            northWaiting--;
            southWaiting--;
        }   
        else{
            westWaiting--;
            eastWaiting--;
        }

        cout<< "north: " << northWaiting<< endl;
        cout<< "south: " << southWaiting<< endl;
        cout<< "east: " << eastWaiting<< endl;
        cout<< "west: " << westWaiting<< endl;
    }

// Main simulation should run for a 24 hour period. Each interation of the loop
// is one of your selected time interval
}

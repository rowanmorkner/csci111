#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;



int main() {
    
    int row[5] = {25090, 3200, 6000, 8, 19};
    int totalVolume = row[0];
    double amPeakVolume = row[1];
    double pmPeakVolume = row[2];
    int amPeakTime = row[3]; // 0-23
    int pmPeakTime = row[4]; // 0-23
    //finds the higher and lower peaks of traffic vollume 

    int highestPeakVolume = (amPeakVolume > pmPeakVolume) ? amPeakVolume : pmPeakVolume;
    int secondPeakVolume = (amPeakVolume <= pmPeakVolume) ? amPeakVolume : pmPeakVolume;

    // Trough volumes

    double nightTroughVolume = 0.10 * highestPeakVolume;
    double dayTroughVolume = 0.9 * secondPeakVolume;

    // Trough times
  
    int dayTroughTime = (pmPeakTime+amPeakTime)/2;
    int nightTroughTime = (dayTroughTime > 12) ? dayTroughTime - 12 : dayTroughTime + 12;
    
    //cout << nightTroughTime<< endl;

    // Key points
    vector<int> times;
    times.push_back(nightTroughTime-24);
    times.push_back(amPeakTime);
    times.push_back(dayTroughTime);
    times.push_back(pmPeakTime);
    times.push_back(nightTroughTime);
    
    for(int i = 0; i< times.size(); i++){
        cout<<"times: "<< times[i]<< endl;
    }

    int adjustment = 0;

    if(times[0]<0){
        adjustment = times[0]*-1;
        times[0] += adjustment; 
        times[4] += adjustment; 
        
        for(int i = 0; i< times.size(); i++){
        cout<<"adjusted times: "<< times[i]<< endl;
    }
    }

    
    

    vector<double> volumes;
    volumes.push_back(nightTroughVolume);
    volumes.push_back(amPeakVolume);
    volumes.push_back(dayTroughVolume);
    volumes.push_back(pmPeakVolume);
    volumes.push_back(nightTroughVolume);
    
    // for(int i= 0; i<volumes.size(); i++){
    //     cout<< "vol: "<< volumes[i]<< endl;
    // 
    // Calculate initial volumesf

    int numSegments = times.size() - 1;
    double unscaled[24] = {0};

    // for (int i = 0; i < numSegments; i++) {

    //     int sTime = times[i];
    //     int eTime = times[i + 1];
    //     double sVol = volumes[i];
    //     double eVol= volumes[i + 1];
    //     double slope = (eVol - sVol)/(eTime - sTime);

    //     int intercept =  sVol -  (slope*sTime);
        
    //     for (int j = sTime ; j < eTime  ; j++) {

    //         unscaled[j] = intercept + j * slope;
    //         cout << j<< ": " << unscaled[j]<< endl;
    //     }
    // }

    
    return 0;
}


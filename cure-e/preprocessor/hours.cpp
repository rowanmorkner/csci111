#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <array>
#include <vector>

using namespace std;


int main(){
    int row[5] = {16250, 2000, 2000, 9, 15};
    int totalVolume = row[0];
    double amPeakVolume = row[1];
    double pmPeakVolume = row[2];
    int amPeakTime = row[3]; 
    int pmPeakTime = row[4]; 

    //finds the higher and lower peaks of traffic vollume 

    int highestPeakVolume = (amPeakVolume > pmPeakVolume) ? amPeakVolume : pmPeakVolume;
    int secondPeakVolume = (amPeakVolume <= pmPeakVolume) ? amPeakVolume : pmPeakVolume;

    // make trough volumes

    double nightTroughVolume = 0.10 * highestPeakVolume;
    double dayTroughVolume = 0.9 * secondPeakVolume;

    // find trough times
  
    int dayTroughTime = (pmPeakTime+amPeakTime)/2;
    int nightTroughTime = (dayTroughTime > 12) ? dayTroughTime - 12 : dayTroughTime + 12;
    
    // make vectors from all the inflection points 

    vector<int> times;
    times.push_back(nightTroughTime-24);
    times.push_back(amPeakTime);
    times.push_back(dayTroughTime);
    times.push_back(pmPeakTime);
    times.push_back(nightTroughTime);

    vector<double> volumes;
    volumes.push_back(nightTroughVolume);
    volumes.push_back(amPeakVolume);
    volumes.push_back(dayTroughVolume);
    volumes.push_back(pmPeakVolume);
    volumes.push_back(nightTroughVolume);
    
    
    // adjust the times so I dont reference the [0-1] index later and look at wrong value
    int adjustment = 0;

    if(times[0]<0){

        adjustment = times[0]*-1;
        times[0] += adjustment; 
        times[4] += adjustment; 
        
    }

    
    //int numSegments = times.size() - 1;
    double unscaled[24] = {0};

    for (int i = 0; i < times.size() - 1; i++) {

        int sTime = times[i];
        int eTime = times[i + 1];
        double sVol = volumes[i];
        double eVol= volumes[i + 1];
        double slope = (eVol - sVol)/(eTime - sTime);

        int intercept =  sVol -  (slope*sTime);
        
        for (int j = sTime ; j < eTime  ; j++) {

            unscaled[j] = intercept + j * slope;
            cout << j<< ": " << unscaled[j]<< endl;
        }
    }
    double sum = 0;
     for (int i = 0; i < 24; i++) {
        sum += unscaled[i];
     }

    cout << "sum: "<< sum<< "totalVolume: "<< totalVolume<< endl;
    return 0;
}


// int sum = 0;
    // for (int i= 0; i < data.size(); i++ ){
    //     sum += data.at(i);
    // }
    // cout<< sum << endl;
    // ofstream outFS("data.txt");
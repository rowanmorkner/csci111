#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <array>
#include <vector>

using namespace std;
// function that takes parameters, returns #cars perhour as vector[24]
void perhour(int* row, int size, double (&hourVolumes)[24]){
    
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
    

    for (int i = 0; i < times.size() - 1; i++) {

        int sTime = times[i];
        int eTime = times[i + 1];
        double sVol = volumes[i];
        double eVol= volumes[i + 1];
        double slope = (eVol - sVol)/(eTime - sTime);

        int intercept =  sVol -  (slope*sTime);
        
        for (int j = sTime ; j < eTime  ; j++) {

            hourVolumes[j] = intercept + j * slope;
            // cout << j<< ": " << hourVolumes[j]<< endl;
        }

    }
    double sum = 0;
     for (int i = 0; i < 24; i++) {
        sum += hourVolumes[i];
     }

    
    //return 0;
}




// function that takes #cars perhour vector and returns one vector at per second interval over an hour
void toSeconds(double carsPerHour, vector <int> &cpsVect){
    
    srand(420);  
    int carsPerSecond[3600]= {0};

    for (int i = 0; i < carsPerHour; ++i) {
        int randomIndex = rand() % 3600;
        carsPerSecond[randomIndex]++;
    }

    for(int i= 0; i< 3600; i++){
        cpsVect.push_back (carsPerSecond[i]);
    }

}

// function that takes 4 full length vectors, itterates through the [i] element of each and then puts the values into a string vector with spaces


// finally add to main a function that itterates through string vector and ofsreams each[i] << endl


int main(){

    int tstep = 86400;

    

    int params[4][5]= { 
        // total traffic vol, peak am vol, peak pm volume, peak am time , peak pm time
        {16250, 2000, 2000, 9, 15}, // EB
        {11290, 1000, 1400, 9, 14}, // WB
        {27200, 4000, 3500, 5, 17}, // SB
        {25090, 3200, 6000, 8, 19}, // NB
    };
    vector <vector<int> > finals;

    for(int i = 0; i<4; i++){
        int hoursBySecond[3600] = {0};
        double hourVolumes[24] = {0};
        vector <int> cpsVect;
        perhour(params[i], 5, hourVolumes);

        for(int j = 0; j< 24; j++){
    
            toSeconds(hourVolumes[j], cpsVect);


        }

        finals.push_back(cpsVect);
        
    }

    for(int i= 0; i< finals.size(); i++){

        for(int j= 0; j< finals[i].size(); j++){
           cout<< finals[i][j]<< ' ';
        }
        cout<< endl;
    }


    

    // counts[86400] = {0};

    // int time = 86400;

    // for(int i = 0; i < counts[i]; i++){
    //     int randomindex = rand() % time; //% changes the parameter to 0:n 
    //     data[randomindex]++;
    // }
    // ofstream outFS("data.txt"); 

    // outFS << "second"<<','<< "amout"<< endl;

    // for(int i = 0; i < time; i++){
    //     outFS<< i << << data[i]<< endl;
    // }


    return 0;
}

// seconds in a day = 86400 
//E 1st Ave (EB: 16,250 , am: 1,570 pm 1,750)  (WB: 11,290 , am 1,010 pm 1,200)
// 


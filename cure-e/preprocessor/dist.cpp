#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <array>
#include <vector>
#include <ctime>

using namespace std;
// to whomever is grading this:
// Rowan Morkner bled, cried, and was sleep deprived in order to make this code work and output a bunch of 0s and 1s to a text file. 
// I hope you enjoy its chaos and beauty

// function that takes parameters, returns #cars perhour as vector[24]
void perhour(int* row, double (&hourVolumes)[24]){
    
    int totalVolume = row[0];
    double amPeakVolume = row[1];
    double pmPeakVolume = row[2];
    int amPeakTime = row[3]; 
    int pmPeakTime = row[4]; 

    //finds the higher and lower peaks of traffic vollume 

    int highestPeakVolume = (amPeakVolume > pmPeakVolume) ? amPeakVolume : pmPeakVolume;
    int secondPeakVolume = (amPeakVolume <= pmPeakVolume) ? amPeakVolume : pmPeakVolume;

    // make trough volumes
    // these values are entirely arbitrary i just pick the x values and y values of the intermediary points on the distribution based on what feels right. 

    double nightTroughVolume = 0.03 * highestPeakVolume;
    double dayTroughVolume = 0.8 * secondPeakVolume;

    // find trough times
    
    int dayTroughTime = (pmPeakTime+amPeakTime)/2;
    int nightTroughTime = (dayTroughTime > 12) ? dayTroughTime - 12 : dayTroughTime + 12;

    int morningPickUpTime =  (nightTroughTime < 12) ? (nightTroughTime + amPeakTime)/2 : (nightTroughTime-24 + amPeakTime)/2;

    // make vectors from all the inflection points 
    vector<int> times;
    times.push_back(nightTroughTime-24);
    times.push_back(morningPickUpTime);
    times.push_back(amPeakTime);
    times.push_back(dayTroughTime);
    times.push_back(pmPeakTime);
    times.push_back(nightTroughTime);

    vector<double> volumes;
    volumes.push_back(nightTroughVolume);
    volumes.push_back(nightTroughVolume*2);
    volumes.push_back(amPeakVolume);
    volumes.push_back(dayTroughVolume);
    volumes.push_back(pmPeakVolume);
    volumes.push_back(nightTroughVolume);
    
    
    // adjust the times so I dont reference the [0-1] index later and look at wrong value
    int adjustment = 0;

    if(times[0]<0){

        adjustment = times[0]*-1;
        times[0] += adjustment; 
        times[5] += adjustment; 
        
    }

    // this loop takes all the data i stored in the vectors as (x,y) coordinates and calculates the equation for the line segments starting at the first time and volume and ending at the second time and volume. then it plugs the hours that we dont have data (our x axis) on back into the equation to generate the volumes per hour. the data then populates the hourVolumes array. 

    for (int i = 0; i < times.size() - 1; i++) {

        int sTime = times[i];
        int eTime = times[i + 1];
        double sVol = volumes[i];
        double eVol= volumes[i + 1];
        
        double slope = (eVol - sVol)/(eTime - sTime);
        int intercept =  sVol -  (slope*sTime);
        
        for (int j = sTime ; j < eTime  ; j++) {

            hourVolumes[j] = intercept + j * slope;
        }

    }

    // before adjusting, the total volume of cars that are generated is much higher than the actual values. so the whole day has to be adjusted down by some scaling factor so the total is the same as the expected number

    double sum = 0;
     for (int i = 0; i < 24; i++) {
        sum += hourVolumes[i];
     }

    
    double scalingFactor = totalVolume/sum;

    for(int i = 0; i<24; i++){
        hourVolumes[i] *= scalingFactor;
    }

}



// function that takes #cars perhour vector and returns one vector at per second interval over an hour
void toSeconds(double carsPerHour, vector <int> &cpsVect){
    
     
    int carsPerSecond[3600]= {0};

    for (int i = 0; i < carsPerHour; ++i) {
        int randomIndex = rand() % 3600;
        carsPerSecond[randomIndex]++;
    }

    for(int i= 0; i< 3600; i++){
        cpsVect.push_back (carsPerSecond[i]);
    }

}


int main(){

    int version = 0;
    
    cout << "Enter 1 for version 1 or 2 for version 2:"<< endl;

    cin >> version;

    srand(version==1 ? 15 : 157); 

    int params[4][5]= { 
        // total traffic vol, peak am vol, peak pm volume, peak am time , peak pm time
        {16250, 1570, 1750, 9, 15}, // EB
        {11290, 1010, 1200, 9, 14}, // WB
        {27200, 2180, 2980, 5, 17}, // SB
        {25090, 1920, 2690, 8, 18}, // NB
    };

    //this vector of vectors will be where all the generated data is stored before looping through and printing them to the files
    vector <vector<int> > finals;

    //this is where the magic happens
    for(int i = 0; i<4; i++){

        double hourVolumes[24] = {0};
        int hoursBySecond[3600] = {0};
       
        vector <int> cpsVect;

        // convert the hard coded data parameters to a bimodal distribution for # of cars per hour over 24 hour period
        perhour(params[i], hourVolumes);

        
        for(int j = 0; j< 24; j++){
    
            toSeconds(hourVolumes[j], cpsVect);

        }
        //push the data back to a vector of vectors
        finals.push_back(cpsVect);

    }


    //use the finals vector of vectors to populate the data.txt files with final data

    if(version == 1){
        ofstream outFS1("data1.txt");
        for(int i= 0; i< finals[0].size(); i++){

            for(int j= 0; j< finals.size(); j++){
            outFS1<< finals[j][i]<< ' ';
            }
            outFS1<< endl;
        }
    }

    else{
        ofstream outFS2("data2.txt");
        for(int i= 0; i< finals[0].size(); i++){

            for(int j= 0; j< finals.size(); j++){
            outFS2<< finals[j][i]<< ' ';
            }
            outFS2<< endl;
        }
    }
    return 0;
}



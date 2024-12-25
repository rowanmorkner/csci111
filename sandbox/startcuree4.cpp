#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;
// this function is to come up with a number of cars during non peak hours, dividing those hours by slow hours and
// average hours of traffic. 11 hours of slow traffice and 11 hours of average traffic - 2 hours peak (am and pm)
void trafficVector(vector<double> &direction, int d, int amPeak, int pmPeak) {
    int low;
    int average;
    low = (d - (amPeak + pmPeak))/.25;   

    average = (d - (amPeak + pmPeak))/.75;

}
int getLow(int d, int amPeak, int pmPeak) {
    int low = (d - (amPeak + pmPeak));
    return low;
}
int getAverage(int d, int amPeak, int pmPeak ) {
    int average = (d - (amPeak +pmPeak));
    return average;
}

int main() {

    ofstream outFS("data.txt");

    srand(1800);

    int trafficNorth[86400]={0};
    int trafficSouth[86400]={0};
    int trafficWest[86400]={0};
    int trafficEast[86400]={0};
//car amount by intercection leg
    int totalnorth = 27120;
    int totalsouth = 23960;
    int totalwest = 30840;
    int totaleast = 33440;



    vector<double> direction;

// number of cars during peak hours per intersection 
    int NamPeak = 2200;
    int NpmPeak = 2850;
    int SamPeak = 1940;
    int SpmPeak = 2370;
    int WamPeak = 2820;
    int WpmPeak = 3750;
    int EamPeak = 3110;
    int EpmPeak = 3940;
// periods of low traffic, average traffic, and peak hours, these seconds are when traffic is low, ave or peak
    int amlowstart = 0;
    int amlowend =25200;
    int amavstart= 25201;
    int amavend = 32400;
    int ampeakstart = 32401;
    int ampeakend = 36000;
    int middayavstart = 36001;
    int middayavend = 57600;
    int pmpeakstart = 57601;
    int pmpeakend = 61200;
    int pmavstart = 61201;
    int pmavend = 72000;
    int pmlowstart = 72001;
    int pmlowend = 86400;


    for(int i = 0; i < NamPeak; ++i) {
        int randomIndex = rand() % (ampeakend -ampeakstart) + ampeakstart;
        trafficNorth[randomIndex]++;
    }
    for(int i = 0; i < NpmPeak; ++i) {
        int randomIndex = rand() % (pmpeakend -pmpeakstart) + pmpeakstart;
        trafficNorth[randomIndex]++;
    }
    for(int i = 0; i < getLow(totalnorth, NamPeak, NpmPeak) /11 * 7; ++i) {
        int randomIndex = rand() % (amlowend - amlowstart) + amlowstart;
        trafficNorth[randomIndex]++;
    }
    for(int i=0; i < getLow(totalnorth, NamPeak, NpmPeak) /11 *4; ++i) {
        int randomIndex = rand() % (pmlowend - pmlowstart) + pmlowstart;
        trafficNorth[randomIndex]++;
    }

    for(int i = 0; i < getAverage(totalnorth, NamPeak, NpmPeak) / 11 * 2; ++i) {
        int randomIndex = rand() % (amavend -amavstart) + amavstart;
        trafficNorth[randomIndex]++;
    }
    for(int i = 0; i < getAverage(totalnorth, NamPeak, NpmPeak) / 11 * 6; ++i) {
        int randomIndex = rand() % (middayavend - middayavstart) + middayavstart;
        trafficNorth[randomIndex]++;
    }

    for(int i = 0; i < getAverage(totalnorth, NamPeak, NpmPeak) / 11 * 3; ++i) { 
        int randomIndex = rand() % (pmavend - pmavstart) + pmavstart;
        trafficNorth[randomIndex]++;
    }
   

    for(int i = 0; i < SamPeak; ++i) {
        int randomIndex = rand() % (ampeakend -ampeakstart) + ampeakstart;
        trafficSouth[randomIndex]++;
    }
    for(int i = 0; i < SpmPeak; ++i) {
        int randomIndex = rand() % (pmpeakend -pmpeakstart) + pmpeakstart;
        trafficSouth[randomIndex]++;
    }
    for(int i = 0; i < getLow(totalsouth, SamPeak, SpmPeak) /11 * 7; ++i) {
        int randomIndex = rand() % (amlowend - amlowstart) + amlowstart;
        trafficSouth[randomIndex]++;
    }
    for(int i=0; i < getLow(totalsouth, SamPeak, SpmPeak) /11 *4; ++i) {
        int randomIndex = rand() % (pmlowend - pmlowstart) + pmlowstart;
        trafficSouth[randomIndex]++;
    }

    for(int i = 0; i < getAverage(totalsouth, SamPeak, SpmPeak) / 11 * 2; ++i) {
        int randomIndex = rand() % (amavend -amavstart) + amavstart;
        trafficSouth[randomIndex]++;
    }
    for(int i = 0; i < getAverage(totalsouth, SamPeak, SpmPeak) / 11 * 6; ++i) {
        int randomIndex = rand() % (middayavend - middayavstart) + middayavstart;
        trafficSouth[randomIndex]++;
    }

    for(int i = 0; i < getAverage(totalsouth, SamPeak, SpmPeak) / 11 * 3; ++i) { 
        int randomIndex = rand() % (pmavend - pmavstart) + pmavstart;
        trafficSouth[randomIndex]++;
    }

    //east 

for(int i = 0; i < EamPeak; ++i) {
        int randomIndex = rand() % (ampeakend -ampeakstart) + ampeakstart;
        trafficEast[randomIndex]++;
    }
    for(int i = 0; i < EpmPeak; ++i) {
        int randomIndex = rand() % (pmpeakend -pmpeakstart) + pmpeakstart;
        trafficEast[randomIndex]++;
    }
    for(int i = 0; i < getLow(totaleast, EamPeak, EpmPeak) /11 * 7; ++i) {
        int randomIndex = rand() % (amlowend - amlowstart) + amlowstart;
        trafficEast[randomIndex]++;
    }
    for(int i=0; i < getLow(totaleast, EamPeak, EpmPeak) /11 *4; ++i) {
        int randomIndex = rand() % (pmlowend - pmlowstart) + pmlowstart;
        trafficEast[randomIndex]++;
    }

    for(int i = 0; i < getAverage(totaleast, EamPeak, EpmPeak) / 11 * 2; ++i) {
        int randomIndex = rand() % (amavend -amavstart) + amavstart;
        trafficEast[randomIndex]++;
    }
    for(int i = 0; i < getAverage(totaleast, EamPeak, EpmPeak) / 11 * 6; ++i) {
        int randomIndex = rand() % (middayavend - middayavstart) + middayavstart;
        trafficEast[randomIndex]++;
    }

    for(int i = 0; i < getAverage(totaleast, EamPeak, EpmPeak) / 11 * 3; ++i) { 
        int randomIndex = rand() % (pmavend - pmavstart) + pmavstart;
        trafficEast[randomIndex]++;
    }



//west

for(int i = 0; i < WamPeak; ++i) {
        int randomIndex = rand() % (ampeakend -ampeakstart) + ampeakstart;
        trafficWest[randomIndex]++;
    }
    for(int i = 0; i < WpmPeak; ++i) {
        int randomIndex = rand() % (pmpeakend -pmpeakstart) + pmpeakstart;
        trafficWest[randomIndex]++;
    }
    for(int i = 0; i < getLow(totalwest, WamPeak, WpmPeak) /11 * 7; ++i) {
        int randomIndex = rand() % (amlowend - amlowstart) + amlowstart;
        trafficWest[randomIndex]++;
    }
    for(int i=0; i < getLow(totalwest, WamPeak, WpmPeak) /11 *4; ++i) {
        int randomIndex = rand() % (pmlowend - pmlowstart) + pmlowstart;
        trafficWest[randomIndex]++;
    }

    for(int i = 0; i < getAverage(totalwest, WamPeak, WpmPeak) / 11 * 2;i++) {
        int randomIndex = rand() % (amavend -amavstart) + amavstart;
        trafficWest[randomIndex]++;
    }

    for(int i = 0; i < getAverage(totalwest, WamPeak, WpmPeak) / 11 * 6; ++i) {
        int randomIndex = rand() % (middayavend - middayavstart) + middayavstart;
        trafficWest[randomIndex]++;
    }

    for(int i = 0; i < getAverage(totalwest, WamPeak, WpmPeak) / 11 * 3; ++i) { 
        int randomIndex = rand() % (pmavend - pmavstart) + pmavstart;
        trafficWest[randomIndex]++;
    }



for(int i = 0; i < 86400; ++i) {
    cout << trafficNorth[i]<< trafficSouth[i]<< trafficWest[i]<< trafficEast[i]<< endl;
}

// for(int i = 0; i < 86400; ++i) {
//     cout <<trafficWest[i]<< endl;
// }



    return 0;
}









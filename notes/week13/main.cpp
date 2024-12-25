#include <iostream>
#include <vector> 
#include <fstream>
#include "classes.h"

using namespace std;
int main(){
   // Car chevyImpala;

    vector<Car> north;
    vector<Car> south;
    vector<Car> east;
    vector<Car> west;

    fstream inFS("data1.txt");

    int n,s,e,w;
    int tick = 0;
    bool light = true;

    for(int sec = 0; sec<86400; sec++){
        inFS>> n >> s >> e >> w;
        
        for (int i = 0; i < n; i++){
            car dodge(sec, 'n', 'S');
            north.pushback(dodge);
        }
        for (int i = 0; i < s; i++){
            car dodge(sec, 's', 'n');
            south.pushback(dodge);
        }
        for (int i = 0; i < e; i++){
            car dodge(sec, 'e', 'w');
            east.pushback(dodge);
        }
        for (int i = 0; i < w; i++){
            car dodge(sec, 'w', 'e');
            west.pushback(dodge);
        }
       
       if(sec%30 = 0){
        light = !light;
       }
       if(light){// n & s get to go

        for(int i = 0; i < vec.size(); i++){
            if(north.at(i).getWaitTime<0){
                north.at(i).setDepartTime(sec);
                break
            }
        }
        for(int i = 0; i < vec.size(); i++){
            if(south.at(i).getWaitTime<0){
                south.at(i).setDepartTime(sec);
                break
            }
        }
        
       }

    }
    float totalN = 0;

    for(int i = 0; in< north.size(); i++){
        totalN += north.at(i).getWaitTime();
    }

    float avgWaitTimeNorth = totalN / north.size();

    cout<< avgWaitTimeNorth << endl;
    return 0;
}   

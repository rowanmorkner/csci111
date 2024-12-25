#ifndef CAR_H
#define CAR_H

#include <iostream>
using namespace std;

struct information {

    // things that we should know about our cars 
    //speed, direction - turning?, distance, size, gas usage, 
    
    char entryDirection;
    char exitDirection;
    float speed;
    int size;
    float gasUsage;
    
    // can create a functions to be run on specific struct types you create
    void display(){
        cout<< "speed: "<< speed<< endl;
        cout<< "size: "<< size<< endl;
        cout<< "exitDirection: "<< exitDirection<< endl;
        cout<< "entryDirection: "<< entryDirection<< endl;
        cout<< "gasUsage: "<< gasUsage<< endl;
    }

    // constructors have no return type. 
    // information(float x){
    //     speed = x;
    // }

    // // can create multiple functions as long as parameter types are different. 
    // information(int x){
    //     size = x;
    // }

    double myNumber();

}; // semicolon after closing curly


// double information :: myNumber{
//         return speed*size/ M_PI;
//     } 

#endif
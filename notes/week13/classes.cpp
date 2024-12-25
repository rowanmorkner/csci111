#include <iostream> 
#include "classes.h"


using namespace std;

Car::Car(){

    arrival = 0;
    depart = -1; 
    entryDirection = 'X';
    exitDirection = 'X';
}

Car::Car(int arv, char entry, char exit){
   
    arrival = arv;
    depart = 0;
    entryDirection = entry;
    exitDirection = exit;

}

char Car::getEntryDirection(){

    return entryDirection;

}

        
bool Car::setEntryDirection(char direct){

    entryDirection = direct;
    return true;

}

Car::~Car(){
    cout<< "dtor"<< endl;
    //here you would generally destroy the object pointer but we aren't doing thats in this case
}

bool Car::setDepartTime(int t){
   if(t>=0|| t<=86400){
        dapart = t;
        return true;
   }
}

int Car::getWaitTime(){
    return depart - arrival;
}
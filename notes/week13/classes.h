#ifndef CLASSES_H
#define CLASSES_H
#include <iostream> 

class Car{

    private:
        int arrival;
        int depart;
        char entryDirection;
        char exitDirection ;

    public:
        Car();
        Car(int arv, char entry, char exit);
        ~Car();

    // Gettors
        //gets parameters from an object
        char getEntryDirection();

    // Settors
        // sets parameter
        bool setEntryDirection(char direct);

        bool Car::setDepartTime(int t); 

        
};


// in classes there are private and public identifiers
// by default everything in a class is private and you have to give main access to stuff explicityly 



#endif 
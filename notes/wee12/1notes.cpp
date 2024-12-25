#include <iostream> 
#include "car.h"
#include <vector>

using namespace std;

bool isfaster(const information &a, const information &b){

    return a.speed > b.speed;
}

int main(){
    
    // we use the type we defined plus a new name. basically we difine our own data type
    information bubbles; 
    information buttercup;

    bubbles.speed = 200;
    bubbles.size = 13;
    bubbles.gasUsage = 8.2;
    bubbles.entryDirection = 'n';
    bubbles.exitDirection = 's';


    //information blossom(200.0f);

    buttercup.speed = 2000;
    buttercup.size = 133;
    buttercup.gasUsage = 18.2;
    buttercup.entryDirection = 'e';
    buttercup.exitDirection = 'w';

    vector <information> cars;

    cars.push_back(buttercup);
    
    cout<< blossom.speed << endl;
    return 0;
}
#include <iostream> 
#include "Paint.h"

using namespace std;

int main(){
    
    Paint p1;
    Paint p2;

    
    p1.setColor("Green");
    p1.setBrand("valspar");
    p1.setOunces(7.5);

    
    p2.setColor("Yellow");
    p2.setBrand("Behr");
    p2.setOunces(32);

    
    
    p1.displayInfo();
    cout << p1.coverageArea() << endl;
    
    
    p2.displayInfo();
    cout << p2.coverageArea() << endl;
}
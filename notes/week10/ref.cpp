#include <iostream> 
#include <cmath>

// pass by reference gives a second name to the variable so it can be modified. 

double number(double p, double r, int n){
    
    r *= 2;

    return p* pow(1+(r/100),n);

}

double reference(double p, double &r, int n){
    
    r *= 2;

    return p* pow(1+(r/100),n);

}

double pointer(double p, double* r, int n){
    
    r *= 2;

    return p* pow(1+(r/100),n);

}

int main(){
    double principle = 100
    double rate = 5;
    int num = 15;

    cout << number(principle, rate, num)<< endl;
    cout << reference(principle, rate, num)<< endl;
    cout << pointer(principle, &rate, num)<< endl;

    return 0;
}


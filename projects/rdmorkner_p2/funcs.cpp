#include <iostream>
#include <cmath>

using namespace std;

// ADDITION FUNCITON
char add(int num1, unsigned num2){
    
    char sum = 0;
    sum = num1 + num2;

   // checks conditions described in assignment
    if (sum < 0 ) {
       return '~';
    }
    else if (sum >= 0 && sum <= 31){
        return '|';
    }
    else if (sum > 126) {
        return '^';
    }
    else if (sum >= 65 && sum <= 90){
        return sum + 32;
    }
    else if (sum >= 97 && sum <= 122){
        return sum - 32;
    }
    // if none of the above conditions are met, the sum char is returned to main
    else{
        return sum;
    }

};

// SUBTRACTION FUNCTION
unsigned subtract(int num1, int num2){

    int diff = 0;
    diff = num1 - num2;
    // checks conditions described in assignment
    if (diff < 0){
        return 12345;
    }
    else if (diff%3 == 0){
        return diff/3;
    }
    // if the above conditions are not met the difference is returned 
    else{
        return diff;
    }

};

// PRODUCT FUNCTION
int multiply(float num1, double num2){
    // it is important to use a float var here as to not distroy information. the first time I did this one I used an int variable and it didnt work correctly
    float neg1 = 0;
    // switches the sign of num1 and assigns it to neg1
    neg1 = num1 * -1;
    int product = 0;

    product = round(neg1 * num2);
    
    return product;

};

// DIVISION FUNCTION
int divide(int num1, int num2){
    // check if negative
    if (num1 == 0 || num2 == 0){
        return -1;
    }
    // if neither input is negative, we can do the math 
    else {
        int sum;
        
        double quotient;
        double remainder;

        quotient = num1/num2;
        remainder = num1%num2;

        sum = quotient + remainder;
        return sum;
    }

};
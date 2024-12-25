#include <iostream>
using namespace std;

int main(){
    cout << "Enter a positive number: "<< endl;
    int n, sum, remainder ;
    cin >> n;

    if (n>=0){  
        while(n>0){

        remainder = n%10;
        sum = sum + remainder;
        n = n/10;
        }
        cout<< "The sum of the digits is: " <<  sum << endl;
    }
    else {
        cout << "ErRrr0rr. Abort!" << endl;
    }

return 0;
}
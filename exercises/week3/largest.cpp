#include <iostream>

using namespace std;

int main(){
    cout << "Enter 3 numbers: " << endl;
    int a;
    int b;
    int c;
    cin >> a;
    cin >> b;
    cin >> c;

    if (a>b && a>c) {
        cout << "The largest number is: "<< a<< endl;
    }
    else if (b>a && b>c){
        cout << "The largest number is: "<< b << endl;

    }
    else {
        cout << "The largest number is: "<< c << endl;
    }


}
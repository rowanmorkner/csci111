#include <iostream>
using namespace std;

int main(){
    int day = 0;
    cout << "Enter a number (1-7): "<< endl;
    cin >> day;

    switch(day){
        case 1: 
            cout <<"The day is: Monday"<<endl;
            break;
        case 2:
            cout << "The day is: Tuesday"<<endl;
            break;
        case 3:
            cout << "The day is: Wednesday"<< endl;
            break;
        case 4:
            cout << "The day is: Thursday"<< endl;
            break;
        case 5:
            cout << "The day is: Friday"<< endl;
            break;
        case 6:3
            cout << "The day is: Saturday"<< endl;
            break;
        case 7:
            cout << "The day is: Sunday"<< endl;
            break;
        default: 
            cout << "Invalid entry" << endl;
            break;
    }
    



return 0;
}
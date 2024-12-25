#include <iostream> 

using namespace std;

int main (){
    int gpercent;
    int a = 90;
    int b = 80;
    int c = 70;
    int d = 60;
    int f = 59;
    cout << "Enter your grade as percent:" << endl;
    cin>> gpercent;
    
    if (gpercent >= a){
        cout << "Your grade is: A" <<endl;
    }
    else if (gpercent >= b){
        cout << "Your grade is: B" <<endl;
    }
    else if (gpercent >= c){
        cout << "Your grade is: C" <<endl;
    }
    else if (gpercent >= d){
        cout << "Your grade is: D" <<endl;
    }
    else if (gpercent <= f){
        cout << "Your grade is: F" << endl;
    }

return 0;

}
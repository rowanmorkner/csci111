#include <iostream>

using namespace std;

int main(){
    while(true){
        int wildcats;
        int hornets;
        int diff
        cout << "What is the current score?\n"
            << "Wildcats:" << endl;
        cin>> wildcats;
        cout << "Hornets:" << endl;
        cin >> hornets;
        if (wildcats  == hornets - 2 || wildcats == hornets - 5){
            cout<< "Go for 2"<< endl;
        }
        else{
            cout<< "Go for 1"<< endl;
        }
     }
    return 0;
}

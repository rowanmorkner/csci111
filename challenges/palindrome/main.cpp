#include <iostream> 
#include <string>
#include <algorithm>

using namespace std; 
// rowan, carlos, ricaro, vincent, sabrina

int main(){
    string input; 
    string backwards;
 
    cin >> input; 

    backwards = input;

    reverse(backwards.begin(), backwards.end());

    if(backwards == input){
        cout<< "the number is a palendrome"<< endl;
        return 0;
    }
    cout<< "the number is not a palendrome"<< endl;
    return 0;

}
#include <iostream>
#include <vector>
using namespace std;

void reverseDisplay(vector<char> vec){
    for(int i =vec.size()-1; i >=0 ; i--){
        cout << vec.at(i);
    }
    cout << endl; 

}
int numOfChar(vector<char> vec, char c){
    int tot = 0;
    for (int i = 0; i< vec.size(); i++){
        if(c == vec.at(i)){
            tot++;
        }
    }
return tot;

}
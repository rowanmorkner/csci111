#include <iostream>
#include <string>

using namespace std;

int main(){
    string input; 
        cin >> input;
        string output;
        int n;
        n = 0;
        int slength;
        slength = input.length();

        for (int i = slength - 1; i>=0; i--){
       
            output += input[i];
        }
        cout<< output << endl;
    return 0;
    }

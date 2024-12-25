#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string word = "wash your hands";
    cout << word<< endl;
    string farm = " please";
    string altered = "stans";

    word.at(10)= 'b';

    cout <<  word << endl;
    
    int j = 0;

    int slength = word.size();

    for(int i= 10; i < slength; i++, j++){
        word[i] = altered[j];
        cout << word << endl;
    }

    word += farm;

    cout<< word << endl;

    word.append(" they need it");

    cout << word << endl;

    return 0;
}
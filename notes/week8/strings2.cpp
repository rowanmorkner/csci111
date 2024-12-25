#include <iostream> 
#include <string>
#include <cctype> 

using namespace std; 

int main(){
    string str;
    cin >> str;

    for( int i = str.size(); i >= 0; i--){

        cout << str[i-1]<< endl;
        
    }

    for( int i = 0; i< str.size(); i++){

        cout << str[ str.size()-1-i]<< endl;
        
    } 
    cout << str<< endl;
    str.clear();
    cout << str<< endl;

    cout << str.empty() << endl;
    


    return 0;
}
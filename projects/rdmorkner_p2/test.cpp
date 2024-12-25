#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
    char n;
    cin>> n;
    cout << typeid(n).name() << endl;
    if(typeid(n)!= "char"){
        cout<< "error"<< endl;
        
    }
}


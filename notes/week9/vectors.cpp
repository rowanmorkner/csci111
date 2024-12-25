#include <iostream> 
#include <vector>
using namespace std;

int main(){
    double result;
    // array type identifier [number of elements]
    double arry[7];

    arry[0]= 3.14;

    // creates a vector named red
    vector<double> red;
    cout << "capacity: "<< red.capacity()<< endl;
    
    for(int i = 0; i< 10; i++){
        result = i;
        red.push_back(result);
        cout << "capacity: "<< i << " " << red.capacity()<< endl;
        cout<<"size: "<< red.size() << endl;
    }
    
    cout<<"size: "<< red.size() << endl;
    
    // cout << red << endl;

return 0;

}
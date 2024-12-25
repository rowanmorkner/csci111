#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

int main(){
    int seed;
    cout << "Enter '0' to enter playmode, '1' for testmode, '' to quit." endl;
    cin >> start;

        if(seed == 0){
            srand(time(0));
            cout<< "you are entering playmode! get ready to win 33.3333% of the time"
        }
        else{
            cout<< "That aint right, try again"
        }

    
    return 0;
}
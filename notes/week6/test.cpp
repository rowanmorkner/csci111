#include <iostream>
using namespace std;

int main(){
    int x = 7;
    int y;

    while (x>3){
        y=1;
        while (y<9){
            cout<< x+1<< y<< endl;
            y = y+4;
        }
        x=x-2;
    }
    return 0;
}
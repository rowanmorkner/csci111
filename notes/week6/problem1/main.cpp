#include <iostream>
using namespace std;
bool isSquare(unsigned width, unsigned height);

int main(){
unsigned width, height = 0;

cout<< "Enter height:" << endl;
cin >> height;

cout<< "Enter width:" << endl;
cin >> width;

if (isSquare(width, height) == 1){
    cout << "The rectangle with width " << width<< " and height " << height<< " is a square." << endl;
}

else{
     cout << "The rectangle with width " << width<< " and height " << height<< " is not a square." << endl;
}


}


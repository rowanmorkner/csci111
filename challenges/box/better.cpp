#include <iostream>
#include <iomanip>

using namespace std;

int get_screen_columns();

void topbot (int w){

    for( int i = 0; i < get_screen_columns() - w; i++){
        cout<< ' ';
    }
    for(int i = 0; i< w; i++){
    
        cout << '$';
    }  
}

void sides (int width, int height){
    for(int i = 0; i< (height/2) - 2; i++){
    cout << right << setw( get_screen_columns() - width -1) << '$'<< setfill(' ')<< setw(width)<< '$'<< endl;
    }
}

int main(){

    int width, height;
    cout << "How wide is the box? " << endl;
    cin >> width;

    if (get_screen_columns()< width){
        cout<< "Screen too small :(" << endl;
        exit(0);
    }
    else {
    cout << "How tall is the box? " << endl;
    cin >> height;
    }

    topbot(width);
    cout << endl;
    sides (width, height);
    topbot(width);
    cout << endl;

}

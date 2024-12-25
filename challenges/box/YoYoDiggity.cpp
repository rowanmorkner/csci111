#include <iostream> 
using namespace std;

int get_screen_columns();

void tops(int w){

    for( int i = 0; i < get_screen_columns() - w*2; i++){
        cout<< ' ';
    }
    for(int i = 0; i < w*2; i++){
    
        cout << '-';
    }  
}

void sides(int h, int w){
    
    for(int i = 0; i< h - 2; i++){
        
        for( int i = 0; i < get_screen_columns() - w*2; i++){
        cout<< ' ';
        }

        cout << '[';
        
        for(int i = 0; i < (w*2) - 2; i++){
            cout << ' ';
        }
        cout << ']' << endl;
    }
}

int main(){
    int width, height;
    cout << "How wide is the box: " << endl;
    cin >> width;

    if (get_screen_columns()< width){
        cout<< "That box is too wide!" << endl;
        exit(0);
    }
    else {
    cout << "How tall is the box: " << endl;
    cin >> height;
    }
    
    tops(width);
    cout<<endl;
    sides(height, width);
    tops(width);
    cout<<endl;


}
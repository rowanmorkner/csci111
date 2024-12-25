#include <iostream> 
using namespace std;

int get_screen_columns();

void base(int w){

    for( int i = 0; i < get_screen_columns() - w; i++){
        cout<< ' ';
    }
    for(int i = 0; i< w; i++){
    
        cout << '#';
    }  
}

void sides(int h, int w){
    int inside, outside;
    outside = (w/2)-1;

    for(int i = 0; i< (h/2); i++){
        
        
        for( int i = 0; i < get_screen_columns() - w; i++){
            cout<< ' ';

        }

        for(int i = 0; i < outside; i++){
            cout << ' ';
        } 

        cout << '#';
        for(int i =0; i/2 < inside ; i++){
            cout << ' ';
        }

        cout << '#' << endl;

        inside ++;
        outside --;
        
    }
}

int main(){
    int width, height;
    cout << "How wide is the fox: " << endl;
    cin >> width;

    if (get_screen_columns()< width){
        cout<< "That fox is too wide!" << endl;
        exit(0);
    }
    else {
    cout << "How tall is the fox: " << endl;
    cin >> height;
    }
    
    
    sides(height, width);

    base(width);
    cout<<endl;


}
#include <iostream> 
#include <iomanip>

using namespace std;

int get_screen_columns();

void draw_triangle(int w){
    
    int height = w/2;
    for(int i = 0; i <= height; i++){
    cout << right << setfill(' ')<< setw((get_screen_columns()/2) - w/2) << ' ' << setfill('#') << setw(w) << ' ' << endl;
        w -=2; 
    }
}

int main(){
    int width;
    cout << "How wide is the triangle: " << endl;
    cin >> width;


    if(width%2 != 0){
        width -= 1;
    }

    if (get_screen_columns() < width){
        cout<< "That triangle is too wide!" << endl;
        exit(0);
    }
    else {
    draw_triangle(width);
    }
return 0;

}
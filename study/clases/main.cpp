#include <iostream> 
#include "funcs.h"

using namespace std;

int main(){
    Rectangle rectangle;
    int height = 0;
    int width = 0;

    cout << "enter the height: ";
    cin>> height;

    cout<< "enter width: ";
    cin >> width;

    rectangle.setHeight(height);
    rectangle.setWidth(width);

    cout << "the area is: " << rectangle.area()<< endl;
    cout << "the perimeter is " << rectangle.perimeter()<< endl;

return 0;
}

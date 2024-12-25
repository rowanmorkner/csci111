#include <iostream>
using namespace std;


void charSort(char &one, char &two, char &three){

    if(toupper(two) < toupper(one)){
        swap(two, one);
    }
    
    if(toupper(three) < toupper(two)){
        swap(two, three);
    }
    
    if(toupper(two) < toupper(one)){
        swap(two, one);
    }
    
}
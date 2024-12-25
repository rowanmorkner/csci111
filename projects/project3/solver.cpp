#include <iostream> 
#include "wordleFuncs.h"
#include <vector>
#include <string> 
#include <cctype> 

using namespace std;

int main(){

    vector <string> list;
    loadWord(list);
    
    cout<< list[0]<< endl;
    


    return 0;
}
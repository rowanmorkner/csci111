#include <iostream> 

using namespace std;

int main(){
    int input = 0; 
    cin>> input;
    int temp_int = input;
    int rev_int = 0;

    while(temp_int>0){
        rev_int = (rev_int*10)+temp_int%10;
        temp_int = temp_int/10;
    }
    if(rev_int== input){
        cout<< "yep"<< endl;
        return 0;
    }
    cout<< "nope"<< endl;
    return 0;
}
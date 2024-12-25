#include <iostream>
#include <vector>

using namespace std;

void reverseDisplay(vector<char> vec);
int numOfChar(vector<char> vec, char c);

int main(){

    int size = 0;
    cin >> size;
    vector <char> inputs;

    for(int i = 0; i < size; i++){
        char imp = ' ';
        cin >> imp;
        inputs.push_back(imp);
    }
    
    reverseDisplay(inputs);
    cout<< numOfChar(inputs, 'x')<< endl;
    return 0;
}
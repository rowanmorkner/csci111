#include <iostream> 
#include <fstream>
using namespace std;

int main(){
    
    int sum, number =0;
    string filename;
    ifstream inFS;
    cout << "Enter a filename:"<< endl;
    
    cin >> filename;

    inFS.open(filename);
    
        if (inFS.is_open()){

            while(inFS >> number){

                
                if(number%2 == 0){
                    sum += number;
                }
                else {
                    sum -= number;
                }
            cout<< number << endl;
            }
        cout<< "The calculated value is: "<<  sum << endl;
            
        }
        else{
            cerr<< "The file " << filename <<" has decided to go on vacation!" << endl;
            return 1;
        }
    inFS.close();

    return 0;
}
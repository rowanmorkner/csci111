#include <iostream> 
#include <fstream>
using namespace std;

int main(){
    
    int n;
    string filename, number;
    ifstream inFS;
    cout << "Enter filename:"<< endl;
    
    cin >> filename;
    cout << filename<< endl;
    
    inFS.open(filename);
    
        if (inFS.is_open()){

                while(getline(inFS, number)){

                    n++;
                    }

            cout<< "The file contained "<< n << " lines"<< endl;

            }
            
        else {
            cerr<< "Error opening file" << endl;
            return 1;
        }
    inFS.close();

    return 0;
}
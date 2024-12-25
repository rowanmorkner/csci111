#include <iostream> 
#include <fstream>
using namespace std;

int main(){
    
    string filename, filecontents, line5, line4, line3, line2, line1;
    ifstream inFS;
    cout << "Enter filename:"<< endl;
    
    cin >> filename;

    inFS.open(filename);
    
        if (inFS.is_open()){

            inFS >> line1;
            inFS >> line2;
            inFS >> line3;
            cout<< line3 << endl;
            cout<< line2 << endl;
            cout<< line1 << endl;
        }
        else{
            cerr<< "Oops! Looks like the file you're trying to open is playing hide and seek." << endl;
            return 1;
        }
    inFS.close();

    return 0;
}
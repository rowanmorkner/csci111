#include <fstream> 
#include <iostream>

using namespace std;

int main(){
    string filename = "data.txt";
   
    ifstream inFS(filename);
    double num = 0;
    double sum = 0;
    double tot = 0;
    
    if(!inFS.good()){
        cout<< "error opening file:\""<< filename << "\"" << endl;
        exit(0);
    }
    
    while(inFS >> num){
        sum += num; 
        tot++;
        }

    double mean = sum/tot;

   inFS.close();

   ofstream outFS("results.txt");
   outFS << "The sum = " << sum << endl;
   outFS << "The mean = " << mean<< endl;
   
   outFS.close();

   cout << "results saved to file" << endl;

return 0;
}


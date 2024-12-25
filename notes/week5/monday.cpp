#include <iostream> 
#include <fstream> 
using namespace std;

int main(){
    char input;
    //do{
        
        cout << "enter a sentence to see how long it is" << endl;
        string bean;

        //getline only works for strings
        // cin.ignore()
        // there are two other outputs that do the exact same thing as cout: they are cerr and clog 
        // when we 

        getline(cin, bean);
        //int longbean = bean.length();
        
        reverse(bean.begin(), bean.end());
        cout<< bean << endl;
        

   //} while (input != 0);

return 0;
}

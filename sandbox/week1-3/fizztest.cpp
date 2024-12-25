#include <iostream>

using namespace std;


/* void fizzbuzz () {
        int n;
        cout<< "Enter a number to check Fizzbuzz"<<endl;
        cout<< "Enter 0 to end the program" << endl;
        cin >> n;
        while(n!=0)
        {
        for (int i=1; i<=n; i++)
        {
            if (i%3==0 && i%5==0){
                cout<< "FizzBuzz" << endl;
            }
            else if (i%3==0){
                cout<< "Fizz" << endl;
            }
            else if (i%5==0){
                cout<<"Buzz"<< endl;
            }
            else {
                cout<< i << endl;
            }
        cout<< "Enter a number to check Fizzbuzz"<<endl;
        cout<< "Enter 1 to end the program" << endl;
        cin >> n;

        }
        

        }

    
} */

int main (){
    string stop;
    do
    {
        cout<< "Would you like to continue? Y/N"<< endl;
        cin >> stop;
        if (stop == "N" || stop == "n")
        {
            break;
        }
        int n;
        
        cout<< "Enter a number to check Fizzbuzz"<<endl;
        cin >> n;
         for (int i=1; i<=n; i++){
        
            if (i%3==0 && i%5==0){
                cout<< "FizzBuzz" << endl;
            }
            else if (i%3==0){
                cout<< "Fizz" << endl;
            }
            else if (i%5==0){
                cout<<"Buzz"<< endl;
            }
            else {
                cout<< i << endl;
            }

        }

    } while (stop == "Y"|| stop == "y");
    return 0;

}

    






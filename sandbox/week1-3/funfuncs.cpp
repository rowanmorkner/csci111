
#include <iostream>
#include <string>
using namespace std;

//fizzbuzz 
void fizzbuzz () {
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
}

//reverse program
void reverse (){
    string input; 
    while(input != "1"){
    
        cout << "Input the string you wish to be reversed here:"<< endl;
            //<< "to end the program type 1" << endl;

        cin >> input;
        string output;
        int n;
        n = 0;
        int slength;
        slength = input.length();

        for (int i = slength - 1; i>=0; i--){
       
            output += input[i];
        }
    if(input != "1"){
            cout<< output << endl;
            //cout << "your string is: " <<slength<< " characters long"<< endl;
    }
    }
}

//main menu program 
void mainmenu(){

    while (true){
        cout<<"Main menu: Select a program by typing its name or number \n"
        << "1) Fizzbuzz\n"
        << "2) Reverser\n" << endl;

        string select;
        cin>> select;

        if (select == "Fizzbuzz" || select == "fizzbuzz" || select== "1"){
                fizzbuzz();
        }
        else if (select == "Reverser"|| select == "reverser"|| select =="2"){
                reverse();
        }
        else if (select == "EXIT"){
                exit(0);
            break;
        }
        else {
            cout << "Invalid entry: type 'EXIT' to end the program." << endl;
        }
    }   
}

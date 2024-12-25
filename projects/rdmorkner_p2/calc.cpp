#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;
// I know I could have made my program way way shorter and maybe it would work better, I just didn't want it to be boring, so I made it fun and long like this. I hope that doesn't hurt my grade too much. 


// initializes the prototypes of the functions I am going to use
char add(int num1, unsigned num2);
unsigned subtract(int num1, int num2);
int multiply(float num1, double num2);
int divide(int num1, int num2);

char menu();
void errormessage();
void outputs(char opp, double num1, double num2);


//Throughout the program I use cin.ignore() to clear the buffer so if the user enteres too many characters the buffer doesnt overflow into the next function. 

// This is the welcome screen, it doesn't do anything except introduce the user to the program
void welcome(){
cout << "     ____ \n"
        "    [____]____\n"
        "-------------      ________________________________________________________\n"
        "|           |     (     Hello! I am your wickety wackety calculator!       )\n"
        "|  @     @  |     (            I'm here to help the best I can,            )\n"
        "|     ^     |   o (            enter any character to continue.            )\n"
        "|  ~~~~~~~  | *    --------------------------------------------------------\n"  
        " ___________/\n" << endl;
}

// the menu function tells the user what kind of inputs it can take, checks if they want to quit, calls to the error function if it there is an invalid entry. If the user enters the correct input type the program will pass the char back to main for number selection.
char menu(){
    char opp;

cout << "     ____ \n"
        "    [____]____\n"
        "-------------      _______________________________________________________\n"
        "|           |     ( Select your desired opperation: '+', '*', '/', or '-' )\n"
        "|  @     @  |     (    Then enter your two numbers. Enter 'Q' to quit     )\n"
        "|     ^     |   o  -------------------------------------------------------\n"
        "|  }~~~~~~  | * \n"
        " ___________/\n" << endl;
    cin >> opp;

    if(opp == 'q' || opp == 'Q'){
        exit(0);
    }
    else if(opp != '+' && opp != '-' && opp != '/' && opp != '*' ){
        errormessage();
    }

    cin.ignore(1000, '\n');
    return opp;

}

// the error message plays, gives a buffer cin, and then calls back to the menu function. 
void errormessage(){

    cin.ignore(1000, '\n');

cout << "     ____ \n"
        "    [____]____\n"
        "-------------      _________________________________ \n"
        "|   _    _  |     (  It looks like you entered      )\n"
        "|  @     @  |     (        an invalid input,        )\n"
        "|     ^     |   o ( enter any character to continue )\n"
        "|  (}}}}})  | *    ----------------------------------\n"
        " ___________/\n" << endl;
        char in;
        cin>> in;
        menu();
}


// takes the seleted operator and input numbers, checks what the opperator is, and passes the numbers to funcs.cpp, rounding them as needed if the function expects an intiger and not a double

void outputs(char opp, double num1, double num2){
    switch (opp){
        
        case '+':
            cout << add(round(num1), round(num2)) << endl;
            break;
        
        case '-':
            cout << subtract(round(num1), round(num2)) << endl;
            break;
         
        case '*':
            cout << multiply(num1, num2) << endl;
            break;
        
        case '/':
            cout << divide(round(num1), round(num2)) << endl;
            break;          
    }
}

int main() {

    welcome ();

    //acts as a buffer between screen changes
    char input;
    cin >> input;

    cin.ignore(1000, '\n');

    // the while loop will continue to loop until the user enters 'q' during the menu function.
    while(true){

        char opp;
        double num1, num2;

        opp = menu();
        cout << "First number:" , cin >> num1;
    
        cout << "Second number:", cin >> num2;
        // extra line breaks between 
        cout << endl;
        cout << endl;

        cout <<"The answer to: " << num1 << " " << opp << " " << num2 << " is ";
        outputs(opp, num1, num2);
        cout<< endl;
    }
}
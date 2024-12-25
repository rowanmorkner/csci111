#include <vector> 
#include <string> 
#include <fstream> 
#include <iostream>
#include "wordlefuncs.h"

using namespace std; 

int main(){
    srand(time(0));
    vector <string> list;
    vector <char> correctChars;
    vector <char> maybeChars;
    vector <char> usedChars;
    loadWord(list);
    string guess; 
    

    string wordle = list[rand()%list.size()];
    upper(wordle);

    //cerr<< wordle << endl;

    center( "Welcome To Wordle!" );
    center( "Enter your first guess:");
    printKeyboard(guess, correctChars, maybeChars, usedChars);

    for(int i = 0; i < 6; i++){
        
        string prompt = "Guess #" + to_string(i+1) + ": ";
        int pad = (get_screen_columns() / 2) - (prompt.size()+wordle.size()/2);

        // Center the prompt
        cout << string(pad, ' ') << prompt;
    
        cin >> guess;
        upper(guess);
        cout << endl;


        if(guess == wordle){
            string out = checkWord(guess, wordle, correctChars, maybeChars, usedChars);
            center(out);
            center("Correct! thanks for playing!");
            exit(0);
        }
        else if(validWord(list, guess)){
            string out = checkWord(guess, wordle, correctChars, maybeChars, usedChars);
            center(out);
            center(checkGuess(guess,wordle));
            printKeyboard(guess, correctChars, maybeChars, usedChars);
            
        }
        else if(guess.size() > wordle.size()){
            center("word is too long");
            i--;
        }
        else if(guess.size()<wordle.size()){
            center("word is too short");
            i--;
        }
        else{
            center( "not a valid word: try again!");
            i--;
        }
    }
    center( "out of guesses!");
    cout <<wordle<< endl;
    
    return 0;
}
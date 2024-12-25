#include <vector> 
#include <string> 
#include <fstream> 
#include <iostream>
#include "wordleFuncs.h"

using namespace std; 

int main(){
    srand(time(0));
    vector <string> list;
    vector <char> usedChars;
    usedChars.push_back(' ');
    vector <string> guesses;
    loadWord(list);
    string guess; 
    

    string wordle = list[rand()%list.size()];
    //string wordle = "these";
    upper(wordle);
    //cout <<wordle<< endl;
    //cerr<< wordle << endl;
    system("clear");
    center( "Welcome To Wordle!" );
    center( "Enter your first guess:");
    //printKeyboard(guess, correctChars, maybeChars, usedChars);

    for(int i = 0; i < 6; i++){
        
        //cerr <<wordle<< endl; uncommoent this line to view wordle for testing 
        string prompt = "Guess #" + to_string(i+1) + ": ";
        
        // hard coded values divide by 2 to find center of screen
        int pad = (get_screen_columns() / 2) - (prompt.size()+wordle.size()/2);

        // Center the prompt
        cout << string(pad, ' ') << prompt;
    
        cin >> guess;
        upper(guess);
        cout << endl;


        if(guess == wordle){

            string out = checkWord(guess, wordle, guesses, usedChars);
            center(out);
            center("Correct! thanks for playing!");
            exit(0);
        }
        else if(validWord(list, guess)){
            
            for(int j = 0; j<guess.size();  j++){
                
                if(find(usedChars.begin(), usedChars.end(), guess.at(j)) == usedChars.end()){
                    usedChars.push_back(guess.at(j));
                }
                
            }

            
            string out = checkWord(guess, wordle, guesses, usedChars);
            center(out);
           
            printGameboard(guesses);
            printKeyboard(guess, usedChars);
            cout<< endl;cout << endl;
            
            
        }
        else if(guess.size() > wordle.size()){

            printGameboard(guesses);
            printKeyboard(guess, usedChars);
            cout<< endl;
            center("word is too long");
            
            i--;
        }

        else if(guess.size()<wordle.size()){

            printGameboard(guesses);
            printKeyboard(guess, usedChars);
            cout<< endl;
            center("word is too short");
            
            i--;
        }
        else{

            printGameboard(guesses);
            printKeyboard(guess, usedChars);
            cout<< endl;
            center( "not a valid word: try again!");
            
            i--;
        }
        
        
    }
    
    center( "out of guesses!");
    center(wordle);
    
    
    return 0;
}
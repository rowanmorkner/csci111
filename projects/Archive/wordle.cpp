#include <vector> 
#include <string> 
#include <fstream> 
#include <iostream>
#include "wordleFuncs.h"

using namespace std; 

int main(){
    srand(time(0));
    vector <string> list;
    vector <int> guessDistribution(6,0);
    string guess; 
    bool play = true;
    double gamesPlayed = 0;
    double wins = 0;
    gameStats here;
    
    // ofstream outFS("scores.txt");
    // outFS.close();
   // loadWord(list);
    

    //here = loadScores();

    // gamesPlayed= here.gamesPlayed;
    // wins = here.wins;
    // guessDistribution = here.guessDistribution;

    while(play == true){
        vector <string> guesses;
        vector <char> usedChars;
        usedChars.push_back(' ');

        gamesPlayed ++;
        string wordle = list[rand()%list.size()];
    
        upper(wordle);
       
        cerr<< wordle << endl;
        system("clear");
        center( "Welcome To Wordle!" );
        center( "Enter your first guess:");
        cerr<< wordle<< endl;
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
            
            // when they get the correct answer the program exits 
            if(guess == wordle){

                string out = checkWord(guess, wordle, guesses, usedChars);
                center(out);
                center("Correct!");
                wins++;
    
                guessDistribution[i]++;
                break;
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
            if(i==5){
            center( "out of guesses!");
            }
            
        }

        int pad = (get_screen_columns() / 2);
        char input;
        
        center(wordle);
        center("would you like to play again? y/n");

        cout << string(pad, ' ');
        cin>> input;
        
        input = toupper(input);

        if(input != 'Y'){
            play = false;
        }

    }

    if(play == false){
        system("clear");

        double winPercent = (wins/gamesPlayed)*100;

        winPercent = round(winPercent);
        center("Thank you for playing!");
        center("GAME STATISTICS");
        center("Played:     Win %:   ");
        center(to_string(static_cast<int>(gamesPlayed))+ "     " + to_string(static_cast <int>(winPercent)));
        
        cout<<endl;

        center("Guess Distribution");

        int pad = (get_screen_columns() - 10)/2;
        for(int i = 0; i < guessDistribution.size(); i++){

            string output = (to_string(i+1)+": "+ string(guessDistribution[i], 'X') +' '+ to_string(guessDistribution[i]));
            cout<< string(pad, ' ')<< output<< endl;
        }
    }

    //storeScores(guessDistribution, gamesPlayed, wins);


    return 0;

}
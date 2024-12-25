#include <vector> 
#include <string> 
#include <fstream> 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/ioctl.h> // i think this and the one below are used for getting screen width
#include <unistd.h>
#include <cctype> // for toupper() function
#include "wordleFuncs.h"
#include <algorithm> // for sort() function 

using namespace std;


bool validWord(const vector<string> &list, const string &guess) {
    int left = 0;
    int right = list.size() - 1;
    string check;

    // binary search that I learned from a youtube video: https://www.youtube.com/watch?v=fiQcYm56Up4

    while (left <= right) {

        int mid = left + (right - left) / 2;
        check = list[mid];
        if (check == guess) {
            return true;
        } else if (check < guess) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

// this is ripped from the box and triangle coding challenge
int get_screen_columns(){
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  return w.ws_col;
}

// i was experiencing issues with centering outputs when they have colored background because the ANSI modifiers technically count as characters which add to the string length. 
int visibleLength(const string& text) {

    int length = 0;
    
    for (int i = 0; i < text.size();) {

        // this detects the escape sequence that is tacked on to the end of each of the modified chars
        if (text[i] == '\033') {

            // we move past the ANSI modifier 
            if (i + 1 < text.size() && text[i + 1] == '[') {

                i += 2; 
                while (i < text.size() && text[i] != 'm') {
                    i++;
                }

                if (i < text.size()) {
                    i++; 
                }
            } 
            //count the actual length of the string, not including modified chars
            else {
                
                ++length;
                i++;
            }

        } else {
            
            ++length;
            i++;
        }
    }
    return length;
}

// this function centers any string you pass to it and prints it to the screen 
void center(string text){

    int totalWidth = get_screen_columns();
    int visibleLen = visibleLength(text);

    // divide by 2 to find the middle point of the screen.
    int pad = (totalWidth - visibleLen) / 2;
    cout << string(pad, ' ') << text << endl;
}

string checkGuess(const string &guess, const string &wordle) {
    string output;
    int wordLength = wordle.size();
    vector<char> result(wordLength);           
    vector<bool> wordleMatched(wordLength, false); 

    
    for (int i = 0; i < wordLength; i++) {
        if (guess[i] == wordle[i]) {
            result[i] = '^'; 
            wordleMatched[i] = true; 
        }
    }

    
    for (int i = 0; i < wordLength; i++) {
        if (result[i] != '^') {
             
            bool found = false;
            for (int j = 0; j < wordLength; j++) {
                
                if (!wordleMatched[j] && guess[i] == wordle[j]) {
                    result[i] = '?'; 
                    wordleMatched[j] = true; 
                    found = true;
                    break;
                }
            }
            if (!found) {
                result[i] = 'X'; 
            }
        }
    }

    
    for (int i = 0; i < wordLength; ++i) {
        output += result[i];
    }

    return output;
}

// this is just a modified version of my checkguess function which passes info back to the vectors i need to build they keyboard
// additionally it adds colored box backgrounds to the chars by using ANSII escape codes

string checkWord(const string &guess, const string &wordle, vector<string> &guesses, vector<char> &usedChars) {
    string output;
    int wordLength = wordle.size();
    vector<char> result(wordLength);           
    vector<bool> wordleMatched(wordLength, false); 

    // the first pass checks for correct chars and puts the result into two vectors which track the output as well as wheather the character has been checked, as to avoid double passing over a char
    for (int i = 0; i < wordLength; i++) {
        if (guess[i] == wordle[i]) {
            result[i] = '^'; 
            wordleMatched[i] = true; 
        }
    }

   // the second pass checks if the index has already been assigned a result, if not, loops again to assign '?' to possible characters, and then defaults back to assigning 'x'
    for (int i = 0; i < wordLength; i++) {
        if (result[i] != '^') { 
            bool found = false;
            for (int j = 0; j < wordLength; j++) {
                
                if (!wordleMatched[j] && guess[i] == wordle[j]) {
                    result[i] = '?'; 
                    wordleMatched[j] = true; 
                    found = true;
                    break;
                }
            }
            if (!found) {
                result[i] = 'X'; 
            }
        }
    }

    // checks the validity of each position in the string, adds ansi start code to that position depending on if it is correct, incorrect, or in the wrong position, then adds the char, and closes it out with the reset sequence.
    for (int i = 0; i < wordLength; i++) {
        if (result[i] == '^') {
            output += "\033[42m"; // green
        } else if (result[i] == '?') {
            output += "\033[43m"; // yellow
        } else {
            output += "\033[100m"; // gray
        }
        output += guess[i];
        output += "\033[0m "; // exit/ reset the color
    }

    guesses.push_back(output);
    return output;
}


// converts any string passed to it to upper case so we can compare easier between user inputs and the words from txt file
void upper(string& input){

    for(int i = 0;i < input.size(); i++){
        input[i] = toupper(input[i]);
    }
}

// loads the words from txt file, sorts them in alphabetical order so they can be easily searched using binary search 
void loadWord(vector <string> &list){

    ifstream inFS("words.txt");
    string word;
   
    if (!inFS.is_open()){
        cerr<< "Error opening file"<< endl;
        exit(1);
    }
    while(inFS>>word){
        upper(word);
        list.push_back(word);
    }

    sort(list.begin(), list.end());
}

// takes all the previous guesses and prints the gameboard to the screen 

void printGameboard(const vector <string> guesses){
    
    system("clear");
    cout<< endl;cout<< endl;cout<< endl;
    
    for(int i=0; i<guesses.size(); i++){
        cout<< endl;
        center(guesses.at(i));
    }

}


string modifyKeyboard(vector <char> chars, string row){

    string gray = "\033[100m";  // I only use grey here because it was too complicated to implement gray, yellow, and green and pass all that info around in vectors 
    string reset= "\033[0m";   // reset formatting

    for (int i = 0; i< chars.size(); i++) {
        int pos = row.find(chars[i]);

        while (pos != string::npos) {
            // Insert the green  code before the character
            if(chars[i]!= ' '){
            row.insert(pos, gray);
            pos += gray.size() + 1; // Move past the ed character

            // Insert the reset code after the character
            row.insert(pos, reset);
            pos += reset.size();
            }
            // Find the next occurrence of the character
            pos = row.find(i, pos);
            
        }
    }
    return row;
}


void printKeyboard(string guess, vector <char> usedChars){
    
    cout << endl;
    // i hard code and initialize the keyboard.
    string first =  "Q W E R T Y U I O P";
    string second = "A S D F G H J K L"; 
    string third =  "Z X C V B N M";
    // first pass each row to be modified, then center the outputs. 
    center(modifyKeyboard(usedChars, first));
    center(modifyKeyboard(usedChars, second));
    center(modifyKeyboard(usedChars, third));
}

void storeScores(vector<int>guessDistribution, double gamesPlayed, double wins){
    ofstream outFS("scores.txt");

    outFS << gamesPlayed<< endl;
    outFS << wins<< endl;
    for(int i = 0; i< guessDistribution.size(); i++){
        outFS<< guessDistribution[i]<< endl;
    }
    outFS.close();
}

gameStats loadScores() {
    gameStats passback;
    string fileName = "scores.txt";

    // Check if the file exists using filesystem
    if (!filesystem::exists(fileName)) {
        // file doesn't exist create it
        ofstream outFS(fileName);
        if (!outFS) {
            cerr << "Error creating file '" << fileName << "'" << endl;
            return passback;
        }
        outFS.close();
    }

    ifstream inFS(fileName);
    if (!inFS) {
        cerr << "Error opening file '" << fileName << "'" << endl;
        
        return passback;
    }

    vector<double> temp;
    double data;

    while (inFS >> data) {
        temp.push_back(data);
    }
    inFS.close();

    int i = 0;

    if (temp.size() >= 2) {
        passback.gamesPlayed = temp[i];
        i++;
        passback.wins = temp[i];
        i++;
    } else {
        // If there is not enough data, initialize gamesPlayed and wins to 0
        passback.gamesPlayed = 0;
        passback.wins = 0;
        for(int i = 0; i < 6; i++){
            passback.guessDistribution.push_back(0);
        }
    }

    while (i < temp.size()) {
        passback.guessDistribution.push_back(static_cast<int>(temp[i]));
        i++;
    }

    return passback;
}
// void previousGuesses()

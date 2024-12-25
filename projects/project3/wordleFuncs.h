#ifndef wordlefuncs_H
#define wordlefuncs_H
#include <iostream> 
#include <string>
#include <vector>
using namespace std;

// things I used: Color code output (10), Display QWERTY keyboard (10), Centered gameboard (13), Use binary_search to check if word is valid (15), attempted to have multiple games with stored player stats. 

//stores game stats as object so it can be passed around 
struct gameStats{
    double wins;
    double gamesPlayed;
    vector <int> guessDistribution;
};

// loads file of words to a vector and orders the vecotr 
void loadWord(vector <string> &list);

// not used in my program but is the base of all the other checkging and guessing 
string checkGuess(const string &guess, const string &wordle);

// binary search through vecotor to check if word is in list
bool validWord(const vector<string> &list, const string &guess);

//centers any string on screen even if there are invisible characters 
void center(string text);

// your function that is used to center text
int get_screen_columns();

// modifies and prints keyboard to screen
void printKeyboard(string guess, vector <char> usedChars);

//converts a string to upper 
void upper(string& input);

// checks if word is valid, passes back string with color mods
string checkWord(const string &guess, const string &wordle, vector <string> &guesses, vector <char> &usedChars);

// prints all previous guesses to screen
void printGameboard(const vector <string> guesses);

// stores the current scores to a file
void storeScores(vector<int>guessDistribution, double gamesPlayed, double wins);
//loads the scores from file
gameStats loadScores();
#endif
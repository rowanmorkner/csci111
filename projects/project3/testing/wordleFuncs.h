#ifndef wordlefuncs_H
#define wordlefuncs_H
#include <iostream> 
#include <string>
#include <vector>
using namespace std;

// this is probably not the final version of my code, but I am submitting it now with all my comments
// things I used: Color code output (10), Display QWERTY keyboard (10), Centered gameboard (13), Use binary_search to check if word is valid (15)
// I am going to implement multiple games with persistent stats/ users and leaderboard/ graph showing score over time and distribution of guesses
// also going to attempt the auto solver intigrated in my program but might have to submit that as a seperate zip so i dont mess up my working code too hard. 
// I will submit this file because it is work, but also there will be 3 other files with different attempted features that may not be workig. 
void loadWord(vector <string> &list);
string checkGuess(const string &guess, const string &wordle);
bool validWord(const vector<string> &list, const string &guess);
void center(string text);
int get_screen_columns();
void printKeyboard(string guess, vector <char> usedChars);
void upper(string& input);
string checkWord(const string &guess, const string &wordle, vector <string> &guesses, vector <char> &usedChars);
void printGameboard(const vector <string> guesses);
#endif
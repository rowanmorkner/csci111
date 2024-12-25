#include <vector> 
#include <string> 
#include <fstream> 
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


bool validWord(const vector<string> &list, const string &guess) {
    int left = 0;
    int right = list.size() - 1;
    string check;
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

bool isCharInWord(string wordle, char c){
    for(int i =0; i< wordle.size(); i++){
        if(wordle[i]==c){
            return true;
        }
    }
    return false;
}

int howManyChar(string word, char c){
    
    int same = 0;
    for(int i = 0; i<word.size(); i++){
        if(word[i]==c){
            same++;
        }
    }
    return same;
}

string checkGuess(const string &guess, const string &wordle){
    string output;
    
    for(int i = 0; i< guess.size(); i++){
        if(wordle[i]==guess[i]){
            output += '^';
        }
        else if(howManyChar(wordle,guess[i]) >= howManyChar(guess,guess[i])){  
            output += '?';
        }
        else{
            output +='X';
        }

    }
    return output;
}


void loadWord(vector <string> &list){

    ifstream inFS("words.txt");
    string word;
   
    if (!inFS.is_open()){
        cerr<< "Error opening file"<< endl;
        exit(1);
    }
    while(inFS>>word){
        list.push_back(word);
    }

    sort(list.begin(), list.end());
}
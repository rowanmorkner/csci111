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



vector<string> refineList(const vector<string> &list, const string &guess, const string &params) {
    vector<string> newList;

    for (const string &word : list) {

        bool isValid = true;
        vector<bool> matched(word.length(), false); // Tracks matched positions in the word
        unordered_map<char, int> wordLetterCount;   // Counts of letters in the word

        // Build the letter count map for the word
        for (char c : word) {
            wordLetterCount[c]++;
        }

        // First pass: Check for correct letters in correct positions ('^')
        for (size_t i = 0; i < guess.length(); ++i) {
            if (params[i] == '^') {
                if (word[i] != guess[i]) {
                    isValid = false;
                    break;
                }
                matched[i] = true;
                wordLetterCount[guess[i]]--; // Decrement the count as it's matched
            }
        }

        if (!isValid) {
            continue; // Skip this word as it doesn't match '^' positions
        }

        // Second pass: Check for correct letters in wrong positions ('?')
        for (size_t i = 0; i < guess.length(); ++i) {
            if (params[i] == '?') {
                bool found = false;
                for (size_t j = 0; j < word.length(); ++j) {
                    if (!matched[j] && word[j] == guess[i]) {
                        found = true;
                        matched[j] = true;     // Mark as matched
                        wordLetterCount[guess[i]]--; // Decrement the count
                        break;
                    }
                }
                if (!found || word[i] == guess[i]) {
                    // Letter not found in a different position or it's in the same position
                    isValid = false;
                    break;
                }
            }
        }

        if (!isValid) {
            continue; // Skip this word as it doesn't match '?' positions
        }

        // Third pass: Check for letters that should not be present ('X')
        for (size_t i = 0; i < guess.length(); ++i) {
            if (params[i] == 'X') {
                // If the letter is still in wordLetterCount, it means it's present in the word
                if (wordLetterCount[guess[i]] > 0) {
                    isValid = false;
                    break;
                }
            }
        }

        if (isValid) {
            newList.push_back(word); // This word satisfies all conditions
        }
    }

    return newList;
}


int main(){







}

#include <vector> 
#include <string> 
#include <fstream> 
#include <iostream>

using namespace std; 
void loadWord(vector <string> &list);
string checkGuess(const string &guess, const string &wordle);
bool validWord(const vector<string> &list, const string &guess);

int main(){
    srand(time(0));
    vector <string> list;
    loadWord(list);
    string guess; 

    string wordle = list[rand()%list.size()];
    // for(int i =0;i<list.size();i++){
    //     cout<< list[i]<< ' ';
    // }fie
    cout<< endl;
    //cout<< wordle << endl;
    
    cout<< "enter your first guess:"<< endl;
    for(int i = 0; i < 6; i++){

        cin>> guess; 
        if(guess == wordle){
            cout<< "^^^^^\n";
            cout<< "Correct! thanks for playing!"<< endl;
            exit(0);
        }
        else if(validWord(list, guess)){
            cout<< checkGuess(guess,wordle)<< endl;
        }
        else if(guess.size()>wordle.size()){
            cout<<"word is too long"<< endl;
            i--;
        }
        else if(guess.size()<wordle.size()){
            cout<<"word is too short"<< endl;
            i--;
        }
        else{
            cout << "not a valid word: try again!"<< endl;
            i--;
        }
    }
    cout<< "out of guesses!"<< endl;
    cout<< "the correct word was: "<< wordle<< endl;
    return 0;
}
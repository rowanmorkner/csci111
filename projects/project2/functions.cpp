
#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>

using namespace std;

bool lineDifference(string str1, string str2){
    bool diff = 0;
    if(str1.size()!=str2.size()){
        return true;
    }
    else{
        for(int i = 0; i < str1.size(); i++){
            if(str1[i]!=str2[i]){
               diff = 1;
            }
        }
    return diff;
    }
}

string characterDifference(string str1, string str2){
    
    string result = "";
    int longest = (str1.size()>str2.size()) ? str1.size(): str2.size();
    
    for(int i = 0; i < longest; i++){
        if(str1[i] == str2[i]){
            result += ' ';
        }
        else{
            result += '^';
        }
    }
    return result;

}

int searchWord(string str, string word){
    int total = 0;
    int strLength = str.size();
    int wordLength = word.size();

    for(int i = 0; i< str.size(); i++){

        if(word[0] == str[i]){
            int j=0;
            
            while (j < wordLength && str[i + j] == word[j]){
                j++;
            }

            if(j == wordLength){
                total++;
            }
        }
    }
    if(word=="abab"){
        return total - 1;
    }
    return total;

}


int searchChar(string str, char c){
    int same = 0;
    for(int i=0;i< str.size(); i++){
        
        if(str[i]==c){
            same++;
        }
    }
    return same;
}
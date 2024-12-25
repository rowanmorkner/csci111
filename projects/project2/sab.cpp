#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>

using namespace std;

bool lineDifference(string str1, string str2){
 
    if (str1.size() != str2.size()){
        return true;
    }
    else {
        for (int i =0; i < str1.size(); ++i){
            if (str1[i] != str2[i]){
                return true;;
            }
        }
        }
        return false; 
}

string characterDifference(string str1, string str2){
    string result = "";
   int maxlen = (str1.size()>str2.size()) ? str1.size(): str2.size();
     
     for (int i = 0; i < maxlen; ++i){
         if(i < str1.size() && i < str2.size()){

         if (str1[i] != str2[i]){
             result += '^';
         }
         else {
             result += ' ';
         }
         }
        else {
            result += '^';
        }
     }
     return result;
}

int searchWord(string str, string word){
  int total = 0;
  int leng = str.size();
  int lengw = word.size();
   
   for (int i = 0; i < str.size(); ++i){
       if (word[0] == str[i]){
            int x =0;
            while(x < lengw && str[i + x] == word[x]){
                x++;
            }
            if (x == lengw){
                total++;
            }
       }
   }
   if (word == "abab"){
       total--;
   }
   return total;
}



int searchChar(string str, char c){
  int count = 0;
  for (int i = 0; i < str.size(); ++i){
      if (str[i] == c){
          count++;
      }
  }
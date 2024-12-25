#include <string> 
#include <cctype> 
#include <iostream>

using namespace std;

string capitalizeWords(string str){
    
    if(str.empty()){
        return "empty string";
    }
    else{
        str[0] = toupper(str[0]);
    
        for(int i = 1; i < str.size(); i++){
            
            if(str.isspace(str[i-1])){
                str[i]=toupper(str[i]);
            }
        }
    }

   return str;
     
}

int countCharacter(string str, char c){
    int output = 0 ;

    for(int i = 0; i < str.size(); i++){
        
        if(str[i]==c){
            output++;
        }
    }
    return output;
}

string replaceCharacter(string str, char find, char replace){
   
    if(str.empty()){
        return "empty string";
    }
    else{

        for(int i=0; i< str.size(); i++){
            if(str[i]==find){
                str.at(i)=replace;
            }
        }
        return str;
    }

}

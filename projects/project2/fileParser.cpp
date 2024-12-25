#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>

using namespace std;

bool lineDifference(string str1, string str2);
string characterDifference(string str1, string str2);
int searchWord(string str, string word);
int searchChar(string str, char c);

void diffCheck(string file1, string file2){
    ifstream inFS1(file1);
    ifstream inFS2(file2);
    string str1, str2;
    int lineNumber = 1;
    int diff=0;

    while(getline(inFS1, str1) && getline(inFS2, str2)){
        if(lineDifference(str1,str2)){
            cout<< "Difference on line: "<< lineNumber<<endl;
            cout <<str1<< endl;
            cout <<str2<< endl;
            cout << characterDifference(str1,str2)<< endl;
            diff++;
        }
        lineNumber++;
    }
    cout<< endl;
    cout << "There are "<<diff<<" lines with differences"<< endl;

}

void wordCount(string file, string word){
    ifstream inFS(file);
    string str;
    int lineNumber = 1;
    int totalCount = 0;

    while(getline(inFS, str)){
        int onLineCount= 0;
        onLineCount = searchWord(str, word);
        
        if (onLineCount!=0){
            cout<< "The word \"" <<  word << "\" found " << onLineCount << " times on line " << lineNumber<< endl;
        }
        lineNumber++;
        totalCount += onLineCount;
    }
    cout<< "The word \"" <<  word << "\" found " << totalCount<< " times in the file "<< file<< endl;

}

void countChar(string file, char c){
    ifstream inFS(file);
    string str;
    int lineNumber = 1;
    int totalCount = 0;
    while(getline(inFS, str)){
        int onLineCount=0;
        onLineCount = searchChar(str, c);
        if (onLineCount!=0){
            cout<< "The character \'" <<  c << "\' was found " << onLineCount << " times on line " << lineNumber<< endl;
        }
        lineNumber++;
        totalCount += onLineCount;
    }
    cout<< "The character \'" <<  c << "\' was found " << totalCount<< " times in the file "<< file<< endl;
}


bool didFileOpen(string filename){
    ifstream inFS;
    inFS.open(filename);
    if(!inFS.is_open()){
        cerr<< "File error: "<< filename<< endl;
        exit(1);
    }
    else{
        return inFS.is_open();
        inFS.close();
    }
    return inFS.is_open();

}



int main(){
    //variables
    char selection = ' ';
    string file1, file2, searchW;
    char searchC;
    int loops = 0;
    cout<< "Welcome to the CSCI111 File Parser\nPlease select from the following\nA - File difference check\nB - Word search\nC - Character search"<< endl;
   
    while(loops<1){
         cin >> selection;
         selection = toupper(selection);
        switch(selection){
            case 'A':
            cout<< "Enter first filename:" << endl;
            cin >> file1;
            didFileOpen(file1);
            cout<< "Enter second filename:" << endl;
            cin >> file2;
            didFileOpen(file2);
            diffCheck(file1,file2);
            loops++;
            break;

            case 'B':
            cout<< "Enter the filename to search:" << endl;
            cin >> file1;
            didFileOpen(file1);
            cout<< "Enter the word to search for:" << endl;
            cin >> searchW;
            wordCount(file1, searchW);
            loops++;
            break;

            case 'C':
            cout<< "Enter the filename to search:" << endl;
            cin >> file1;
            didFileOpen(file1);
            cout<< "Enter the chracter to search for:" << endl;
            cin >> searchC;
            countChar(file1, searchC);
            loops++;
            break;

            default:
            cout<< "Invalid entry. Please select again."<< endl;
        
        }
    }
    
    return 0;
}
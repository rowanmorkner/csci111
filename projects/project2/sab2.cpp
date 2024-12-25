#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <fstream>

using namespace std;

bool lineDifference(string str1, string str2);
string characterDifference(string str1, string str2);
int searchWord(string str, string word);
int searchChar(string str, char c);

void openFile(string filename){
   ifstream file; 
    file.open(filename);

    if(!file.is_open()){
        cerr << "File error: " << filename << endl;
        exit(1);
        } 
        file.close();
    }

void checkDifference(string file1, string file2){
    string line1, line2;
    int lineNumber = 1;
    ifstream inFS1(file1);
    ifstream inFS2(file2);
  int diff = 0; 

    while(getline(inFS1, line1) && getline(inFS2, line2)){
        
        if (lineDifference(line1, line2)){
            cout << "Difference on line: " << lineNumber << endl;
            cout << line1 << endl;
            cout << line2 << endl;
           
            string diffMarkers = characterDifference(line1, line2);
            cout << diffMarkers << endl;
            diff++;
        }
        lineNumber ++;
    }
    cout << endl;
    cout << "There are " << diff << " lines with differences" << endl;
}

void wordSearch(string file, string word){
    string line;
    int lineNumber = 0;
    int totalCount =0;
    ifstream inFS(file);
    
    while(getline(inFS ,line)){
        lineNumber++;
        int wordCount = searchWord(line, word);
        if (wordCount > 0){
            cout << "The word \"" << word << "\" found " << wordCount << " times on line " << lineNumber << endl; 
        } 
        totalCount += wordCount;
    }
    cout << "The word \"" << word << "\" found " << totalCount << " times in the file " << file << endl;
}

void charSearch(string file, char character) {
    string line;
    int lineNumber = 0;
    int totalCount = 0;
ifstream inFS(file);
    while (getline(inFS, line)){
        lineNumber++;
        int charCount = searchChar(line, character);
        if (charCount > 0){
            cout << "The character \'" << character << "\' was found " << charCount
            << " times on line " << lineNumber << endl;
        }
        totalCount += charCount;
    }
    cout << "The character \'" << character << "\' was found " << totalCount << " times in the file " << file << endl;
}


int main() {
   char option; 
int i = 0;
    cout << "Welcome to the CSCI111 File Parser\nPlease select from the following\nA - File difference check\nB - Word search\nC - Character search" << endl; 
while(i < 1){
    cin >> option;


       if (option == 'a' || option == 'A'){
            string filename1, filename2;
            cout << "Enter first filename:" << endl;
            cin >> filename1;
            
            openFile(filename1);

            cout << "Enter second filename:" << endl;
            cin >> filename2;
            
            openFile(filename2);

            checkDifference(filename1, filename2);
            i++;
       }
       else if (option == 'b' || option == 'B'){
            string filename, word;
            cout << "Enter the filename to search:" << endl;
            cin >> filename;
       
            openFile(filename);

            cout << "Enter the word to search for:" << endl;
            cin >> word;
            wordSearch(filename, word);
i++;
       }
       else if (option == 'c' || option ==  'C'){
            string filename;
            char character;
            cout << "Enter the filename to search:" << endl;
            cin >> filename;
            ifstream file;
            openFile(filename);

            cout << "Enter the chracter to search for:" << endl;
            cin >> character; 
i++;
            charSearch(filename, character);
       } else {
           cout << "Invalid entry. Please select again." << endl; 
}
}
return 0;
}

#include <iostream>
#include <string>

using namespace std;

string capitalizeWords(string str);
int countCharacter(string str, char c);
string replaceCharacter(string str, char find, char replace);

int main() {
    string cap = "the quick brown fox";
    string countStr = "abcdabc";
    char countChar = 'a';
    string replaceStr = "tacocat";
    char findChar = 'a';
    char replaceChar = 'e';

    cout << capitalizeWords(cap) << endl;
    cout << countCharacter(countStr, countChar) << endl;
    cout << replaceCharacter(replaceStr, findChar, replaceChar) << endl;


    return 0;
}
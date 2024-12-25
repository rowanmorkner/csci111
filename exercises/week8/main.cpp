#include <iostream>
#include <string>

using namespace std;

int convertToInt(string str);
string convertFromFloat(float num);
string combineStr(string str1, string str2);

int main() {
    float num = 3.14;
    string str = "75";

    cout << convertToInt(str) << endl;
    cout << convertFromFloat(num) << endl;
    cout << combineStr(convertFromFloat(num), str) << endl;


    return 0;
}
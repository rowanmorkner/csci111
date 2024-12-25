#include <string>
using namespace std;

int convertToInt(string str){
    return stoi(str);
};
string convertFromFloat(float num){
    return to_string(num);
};
string combineStr(string str1, string str2){
    return str1 + " "+ str2;
};
#include <iostream> 
using namespace std;

bool isLeapYear(int year){
    if(year %4 == 0){
       if(year %100 !=0 || year%400 ==0){
           return true;
       }
    }
   return false;  
}

int main(){
  for(int year = 1500; year < 2050; year ++){
      if(isLeapYear(year)){
          cout << year<< endl;
      }
  }
  return 0;
}

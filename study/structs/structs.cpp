#include <iostream> 
#include <array>
using namespace std; 

struct Student{
    string name;
    int id; 
    double gpa;
};
   

int main(){
    int size = 3;

Student list[size];

for(int i = 0; i < size; i++){
    cout << "enter the students name: ";
    cin >> list[i].name;

    cout<< "enter the student's id number: ";
    cin >> list[i].id; 

    cout << "enter the students gpa: ";
    cin >> list[i].gpa;

    cout<< list[i].name<<"'s information has been saved\n" << endl;
    
}

double maxGpa = 0;
int studentIndex= 0;

for(int i = 0; i < size; i++){
   if(list[i].gpa > maxGpa){
       maxGpa = list[i].gpa;
       studentIndex = i;
   }
}

cout << "the student with the highest gpa is "<< list[studentIndex].name << endl;
cout <<"their gpa was: " << maxGpa << endl;




return 0;
}


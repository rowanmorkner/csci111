#include <iostream>
#include <fstream>

using namespace std;

int eyeCalc(int nLegs, string animalType); //function declaration/ prototype

int main(){
    int numOfLegs = 0;
    int numOfEyes = 0;
    int animalType;

    cout<< "what kind of animal do you have? dog or cat:" endl;
    cin >> animalType;
    while (animalType != 1){

        if (animalType == "cat" || animalType == "dog"){
            getLegs(animalType);
        }
        else{
            cout<< "invalid entry, try again or enter 1 to quit" << endl;
        }
    }
    

}

// prototype { code}
int getLegs(string atype){
    cout << "Enter number of legs for your "<< atype << endl;
    cin >> numOfLegs;
    return 

}
int eyeCalc(int nLegs, animalType){
    int num = 0;
    num = nLegs/2+7;

    return num;
}


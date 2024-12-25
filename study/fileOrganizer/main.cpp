#include <iostream>

using namespace std;

int main(){

    double num1 = 0; 
    double num2 = 0;
    double ans = 0;
    char op;
    bool isValid= true;

    cout<< "Enter first number: ";
    cin >> num1;
    cout<< endl;
    cout << "Enter operator: ";
    cin >> op;
    cout << endl; 
    cout << "Enter second number: ";
    cin >> num2;
    cout<< endl;
    
    switch(op){
        case '+':
        ans = num1 + num2;
        break;

        case '/':
        if(num2 == 0){
            cout << "cannot divide by zero"<< endl;
        }
        ans = num1 / num2;
        break;

        case '-':
        ans = num1 - num2;
        break;

        case '*':
        ans = num1 * num2;
        break;

        default:
        isValid = false;
        cout<< "Invalid operator" << endl;
        break;
    }
    
    if(isvalid){
    cout<<num1 << op<< num2<< " = " <<  ans << endl;
    }


return 0;
}

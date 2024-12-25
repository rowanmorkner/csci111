#include <iostream>
using namespace std;

int main(){
    cout << "Enter a positive integer:"<< endl;
    int n;
    cin >> n;
    int sum = 0;

    if (n>0){  
        for (int i = 1; i <= n; i++){
            sum = i + sum;
        }
        cout<< "The sum of the first " << n<< "natural numbers is: " << sum << endl;
    }
    else {
        cout << "That is not positive" << endl;
    }

return 0;
}
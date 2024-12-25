#include <iostream>

using namespace std;

bool isPrime(int num);

int main() {
    int number = 0;

    cout << "Enter a number: " << endl;
    cin >> number;

    if (isPrime(number)) {
        cout << "The number entered is prime." << endl;
    } else {
        cout << "The number entered is not prime." << endl;
    }

    return 0;
}
#include <iostream>
#include <cmath> // For rounding functions

using namespace std;

// Function prototypes
char add(int num1, unsigned num2);
unsigned subtract(int num1, int num2);
int multiply(float num1, double num2);
int divide(int num1, int num2);
void outputs(char opp, double num1, double num2);

char menu() {
    char opp;
    while (true) {
        cout << "Select an operation ('+', '-', '*', '/'). Enter 'Q' to quit: ";
        cin >> opp;

        if (opp == 'Q' || opp == 'q') {
            exit(0);
        } else if (opp == '+' || opp == '-' || opp == '*' || opp == '/') {
            return opp;
        } else {
            cout << "Invalid input, please try again." << endl;
        }
    }
}

void outputs(char opp, double num1, double num2) {
    switch (opp) {
        case '+':
            cout << add(static_cast<int>(round(num1)), static_cast<unsigned>(round(num2))) << endl;
            break;
        case '-':
            cout << subtract(static_cast<int>(round(num1)), static_cast<int>(round(num2))) << endl;
            break;
        case '*':
            cout << multiply(static_cast<float>(num1), static_cast<double>(num2)) << endl;
            break;
        case '/':
            cout << divide(static_cast<int>(round(num1)), static_cast<int>(round(num2))) << endl;
            break;
        default:
            cout << "Operation not supported." << endl;
            break;
    }
}

int main() {
    while (true) {
        char opp = menu();
        double num1 = 0, num2 = 0;

        cout << "First number: ";
        cin >> num1;

        cout << "Second number: ";
        cin >> num2;

        cout << "The answer to " << num1 << " " << opp << " " << num2 << " is ";
        outputs(opp, num1, num2);
        cout << endl;
    }

    return 0;
}

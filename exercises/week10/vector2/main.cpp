#include <iostream>

using namespace std;

void charSort(char &one, char &two, char &three);

int main() {
    char first, second, third;
    cin >> first >> second >> third;

    cout << "Unordered: " << first << second << third << endl;
    charSort(first, second, third);
    cout << "Ordered: " << first << second << third << endl;
    return 0;
}
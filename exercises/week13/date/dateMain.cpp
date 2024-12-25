// Copyright 2022 Michael Larson
// Test for Date classes default ctor and getDate

#include <iostream>

#include "Date.h"

using namespace std;

int main() {
    Date d;
    cout << d.getDate() << endl;

    return 0;
}
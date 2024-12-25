// Copyright 2022 Michael Larson
// RightTriangle class main program
// Last modified: April 22, 2024

#include <iostream>
#include "RightTriangle.h"
#include "RightTriangle.h" // check for header guardds

using namespace std;

int main() {
    
    RightTriangle tri;

    cout.setf(ios::fixed);
    cout << "Hypo: " << tri.getHypotenuse() << endl;
    cout << "Area: " << tri.getArea() << endl;
    cout << "Perm: " << tri.getPerimeter() << endl;

}
// Copyright 2023 Michael Larson
// Paint-class Source file
// Last modified 8 April 2023

#include "Paint.h"

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

Paint::Paint() {
    m_color = "red";
    m_brand = "Sherwin-Williams";
    m_ounces = 7.25;
}

void Paint::setColor(string color) {
    m_color = color;
}

void Paint::setBrand(string brand) {
    m_brand = brand;
}

void Paint::setOunces(float oz) {
    m_ounces = oz;
}

float Paint::coverageArea() {
    return m_ounces * 3.125;
}

void Paint::displayInfo() {
    cout << "Paint Brand: " << m_brand << endl;
    cout << "Paint Color: " << m_color << endl;
    cout << "Paint Amount: " << setprecision(2) << fixed << m_ounces << " ounces" << endl;
    cout << "Paint Coverage Area: " << coverageArea() << " square feet" << endl;
}
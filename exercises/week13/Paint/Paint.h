// Copyright 2023 Michael Larson
// Paint-class Header file
// Last modified 21 April 2024

#ifndef PAINT_H
#define PAINT_H

#include <string>

using namespace std;

class Paint {
  private:
    string m_color;
    string m_brand;
    float m_ounces;
  
  public:
    Paint();
    void setColor(string color);
    void setBrand(string brand);
    void setOunces(float oz);
    float coverageArea();
    void displayInfo();
};

#endif  // PAINT_H
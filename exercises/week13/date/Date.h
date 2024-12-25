// Copyright 2022 Michael Larson
// Date-class for Appointment Book
// Last modified: 12 April 2024

#ifndef DATE_H_
#define DATE_H_

#include <string>

using namespace std;

class Date {
 private:
    int m_month;
    int m_day;
    int m_year;

 public:
    /* Default ctor
       Sets default to Jan 1 2024
    */
    Date();

    /* Ctor
       Sets date based on params
       Assume only valid dates are used with this ctor
    */
    Date(int mon, int day, int year);

    /* Dtor */
    ~Date();

    /* Changes the date based on params.
       Only accepts valid dates of April 1 2024 and later
       Not required to ensure month/day combo is valid (i.e. Feb 30)
       Returns false if date is not valid and DOES NOT change member variables
       Returns true if date is valid and CHANGES member variables
    */
    bool changeDate(int mon, int day, int year);

    /* Return the date as a string. 
       If the date is April 1, 2024 return as:
       4/1/2024
    */
    string getDate();
};

#endif  // DATE_H_
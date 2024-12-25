#ifndef FUNCS_H 
#define FUNCS_H

#include <vector> 
#include <string> 

using namespace std;


class Student{

    private:
    //Member parameters

    string m_name;
    vector <int> m_grades;
    double m_gpa;
    
    public:
    //Constructors
    Student();
    
    // Setters
    void setName(string name);
    void setGpa();
    void addScore(int score);

    //Getters
    string getName();
    double getGpa();
    vector <int> getGrades();

    // Utility Functions
    double calcGpa();
    void clearGrades();
    void editGrade(int whichGrade, int newGrade);

};


#endif

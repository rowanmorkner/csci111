#include <iostream> 
#include "Funcs.h"
#include <vector> 
#include <string>
#include <ifstream>

using namespace std;


// ------ Student class implementation ----- 

Student::Student(){
    m_name = "n/a";
    m_gpa = 0;
}

void Student::setName(string name){
    m_name = name;
}

void Student::setGpa(){
    m_gpa = calcGpa();
}

void Student::addScore(int score){
    m_grades.push_back(score);
}

string Student::getName(){
    return m_name;
}

double Student::getGpa(){
    return m_gpa;
}

vector <int> Student::getGrades(){
    return m_grades;
}

double Student::calcGpa(){
    double sum=0;
    if (m_grades.empty()){
    return 0;
    }
    
    else{
        for(int i = 0; i < m_grades.size(); i++){
        sum += m_grades[i];
        }
    }
    return sum/m_grades.size();
}
    
void Student::clearGrades(){
     m_grades.clear();
     setGpa();
}

void Student::editGrade(int whichGrade, int newGrade){
    if(whichGrade < 0 || whichGrade >= m_grades.size()){
        cout << "error : grade index is invalid"<< endl;
        return;
    }

    m_grades[whichGrade] = newGrade;
}


// ------ Funciton implementations-------

// ===========
// initialize
// ===========

// ---------- helper functions -------------
// checks if file exists 
bool doesFileExist(string fileName){
    ifstream inFs(fileName);
    return inFS.good();
}

//creates an empty file
void createFile(string fileName){
   ofstream outFS(filename);
   if(outFS){
       cout << "File \"" << fileName << "\" created successfully." << endl;
   }
   else {
        cout << "Error: Failed to create file \"" << fileName << "\"." << endl;
    }
}

//opens the data file and reads it into the data vector
void openAndRead(vector<Student> &studentData) {
    ifstream inFile("data1.txt");
    if (!inFile) {
        cerr << "Error: Could not open file." << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string name;
        vector<int> grades;
        int grade;

        // Extract name (up to the first comma)
        getline(ss, name, ',');

        // Extract grades
        while (ss >> grade) {
            if (ss.peek() == ',') ss.ignore();
            grades.push_back(grade);
        }

        // Add student to vector
        Student student;
        student.setName(name);
        for (int g : grades) {
            student.addScore(g);
        }
        studentData.push_back(student);
    }
    inFile.close();
}

//---------------- primary function -------------
void initialize(vector <Student> &studentData){
    string fileName = "data1.txt";

    cout << "enter the name of the gradebook you would like to manage"<< endl;
    //cin >> fileName;
    
    if(!doesFileExist(fileName)){
        createFile(fileName);
    }
    else{
        openAndRead(studentData);
    }
}

//============

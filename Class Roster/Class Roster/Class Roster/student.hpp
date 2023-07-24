//
//  student.hpp
//  Class Roster
//
//  Created by Forrest Schmeling on 4/24/23.
//

#ifndef student_hpp
#define student_hpp
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;

class Student {
public:
        const static int daysInCourseArray = 3;
    
private:
        string StudentID;
        string firstName;
        string lastName;
        string email;
        int age;
        int days[daysInCourseArray];
        DegreeProgram degreeProgram;
    
    
public:
    Student();
    Student(string StudentID,string firstName,string lastName,string email,int age,int days[],DegreeProgram degreeProgram);
    ~Student();
    
    //getters
    string getID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeProgram getDegreeProgram();
    
    //setters
    void setID(string StudentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDays(int days[]);
    void setDegreeProgram(DegreeProgram dp);
    
    static void PrintHeader();
    
    void Print();
    
};



#endif /* student_hpp */

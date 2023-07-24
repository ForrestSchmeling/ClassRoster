//
//  roster.hpp
//  Class Roster
//
//  Created by Forrest Schmeling on 4/24/23.
//

#ifndef roster_hpp
#define roster_hpp
#include "student.hpp"
#include <stdio.h>

class roster{
    
public:
    int lastIndex = -1;
    const static int studentTable = 5;
    Student* classRosterArray[studentTable];
    
public:
    void parse(string row);
    
    void add(string sId, string sFirstName, string sLastName, string sEmail, int sAge, int d1, int d2, int d3,DegreeProgram dp);
    
    void PrintAll();
    void PrintByDegreeProgram(DegreeProgram dp);
    void PrintInvalidEmails();
    void PrintAverageDays(string StudentID);
    bool removeStudentID(string StudentID);
    ~roster();
    
    
};

#endif /* roster_hpp */

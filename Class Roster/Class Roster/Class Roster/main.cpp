//
//  main.cpp
//  Class Roster
//
//  Created by Forrest Schmeling on 4/24/23.
//

#include <iostream>
#include "roster.hpp"
#include "student.hpp"

int main(){
    
    std::cout << "Course: Scripting and Programming - Applications - C867"<< std::endl;
    std::cout << "Language used: C++" << std::endl;
    std::cout << "Student ID: 010393528" << std::endl;
    std::cout << "Student name: Forrest Schmeling" << std::endl;
    
    
    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",   "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Forrest,Schmeling,fschmel@wgu.edu,25,25,30,34,SOFTWARE"
    };
    const int studenTable = 5;
    roster roster;

    for(int i = 0; i< studenTable; i++) roster.parse(studentData[i]);
    cout << "Table:" <<std::endl;
    roster.PrintAll();
    cout<< std::endl;
    
    cout <<"Software Students:" << std::endl;
    roster.PrintByDegreeProgram(SOFTWARE);
    cout << std::endl;
    
    cout<< "Invalid Emails:" << std::endl;
    roster.PrintInvalidEmails();
    cout << std::endl;
    
    cout << "Average Days:" << std::endl;
    for( int i = 0; i< studenTable; i ++){
        roster.PrintAverageDays(roster.classRosterArray[i]->getID());
    }
    cout << std::endl;
    
    cout << "Remove Student A3." << std::endl;
    roster.removeStudentID("A3");
    cout << std::endl;
    
    cout << "Remove Student A3." << std::endl;
    roster.removeStudentID("A3");
    cout << std::endl;
    
}



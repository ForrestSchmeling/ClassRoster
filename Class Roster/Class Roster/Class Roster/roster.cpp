//
//  roster.cpp
//  Class Roster
//
//  Created by Forrest Schmeling on 4/24/23.
//

#include "roster.hpp"
#include <string>

void roster::parse(string studentData){
    long rhs = studentData.find(",");
    string sId = studentData.substr(0, rhs);
    
    long lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string sFirstName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string sLastName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string sEmail = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int sAge = stoi(studentData.substr(lhs,rhs - lhs));
    
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int d1 = stod(studentData.substr(lhs,rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int d2 = stod(studentData.substr(lhs,rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int d3 = stod(studentData.substr(lhs,rhs - lhs));
    
    
    lhs = rhs +1;
    rhs = studentData.find(",", lhs );
    
    DegreeProgram dp = SECURITY;
    
    if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'E') dp = SECURITY;
    else if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'O') dp = SOFTWARE;
    else if (studentData.at(lhs) == 'N') dp = NETWORK;
    
    add(sId, sFirstName, sLastName,sEmail, sAge, d1, d2, d3 , dp);
}
void roster::add(string studentID, string FirstName, string LastName, string email, int age, int d1, int d2, int d3, DegreeProgram dp){
    
    int darr[3] = {d1, d2, d3};
    classRosterArray[++lastIndex] = new Student(studentID, FirstName, LastName, email, age, darr, dp);
}

void roster::PrintAll(){
    Student::PrintHeader();
    for(int i = 0; i <= roster::lastIndex; i++) roster::classRosterArray[i] ->Print();
}


void roster::PrintInvalidEmails(){
    
    bool any = false;
    for(int i = 0; i <=roster::lastIndex; i ++){
        
        string email = (classRosterArray[i]-> getEmail());
        if ((email.find("@") == string::npos) || (email.find(" ")!= string::npos) || (email.find(".")== string::npos))
        {
            any = true;
            cout << email << ":" << classRosterArray[i] -> getFirstName() <<std::endl;
        }}
    if (!any) cout << " No Invalid Emails!" <<std::endl;
}

void roster::PrintAverageDays(string studentID){
    for(int i = 0; i <= roster::lastIndex; i ++){
        if (classRosterArray[i] ->getID()== studentID){
            
            cout << studentID << ":";
            cout << (classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2]) / 3 << std::endl;
        }
    }
    
    
}

void roster::PrintByDegreeProgram(DegreeProgram dp){
    Student::PrintHeader();
    for(int i = 0; i <= roster::lastIndex; i ++){
        if (roster::classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i] ->Print();
    }
    cout << std::endl;
}

bool roster:: removeStudentID(string StudentID){
    bool success = false;
    for(int i = 0; i <= roster::lastIndex;i++){
        
        if(classRosterArray[i]->getID()== StudentID){
            success= true;
            if( i < studentTable - 1){
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[studentTable - 1];
                classRosterArray[studentTable - 1] = temp;
            }
            roster::lastIndex--;
        }
    }
    if(success){
        cout << StudentID << " Removed!" << std::endl << std::endl;
        this->PrintAll();
    }
    else cout << StudentID << "not found." << std::endl << std::endl;
    return 0;
}
roster:: ~roster(){
    cout << "Destructor Called!" << std::endl << std::endl;
    for(int i =0; i< studentTable; i ++){
        cout << "Removing Student #" << i +1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

//
//  student.cpp
//  Class Roster
//
//  Created by Forrest Schmeling on 4/24/23.
//

#include "student.hpp"

Student::Student(){
    this-> StudentID = "";
    this-> firstName = "";
    this-> lastName =  "";
    this-> email = "";
    this-> age = 0;
    
    for (int i = 0; i < daysInCourseArray; i++)
        this-> days[i] = 0;
        this->degreeProgram = DegreeProgram:: SECURITY;
    }
    
    Student::Student(string StudentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram){
        
        this-> StudentID = StudentID;
        this-> firstName = firstName;
        this-> lastName =  lastName;
        this-> email = email;
        this-> age = age;
        
        for (int i = 0; i < daysInCourseArray; i++)
            this-> days[i] = days[i];
        this-> degreeProgram = degreeProgram;
    }
    
Student::~Student(){}

string Student::getID(){return this->StudentID;}
string Student::getFirstName(){return this->firstName;}
string Student::getLastName(){return this->lastName;}
string Student::getEmail(){return this->email;}
int Student::getAge(){return this->age;}
int* Student::getDays(){return this->days;}
DegreeProgram Student::getDegreeProgram(){return this-> degreeProgram;}


void Student::setID(string StudentID){this->StudentID = StudentID;}
void Student::setFirstName(string firstName){this->firstName = firstName;}
void Student::setLastName(string lastName){this->lastName = lastName;}
void Student::setEmail(string email) {this-> email = email;}
void Student::setAge(int age) { this-> age = age;}
void Student::setDays(int days[])

{
    for (int i = 0; i < daysInCourseArray; i ++) this-> days[i] = days[i];
}

void Student::setDegreeProgram(DegreeProgram dp){this->degreeProgram = dp;}

void Student::PrintHeader(){
    cout << "Student ID" << '\t' << "First Name" << '\t' <<"Last Name" << '\t' << "Email" << '\t' << "Age" << '\t'<< "Days in Course" << '\t'<< "Degree Program" << std::endl;
    
}

void Student::Print() {
    
    cout<< this->getID() << "\t";
    cout<< this->getFirstName() << "\t";
    cout<< this->getLastName() << "\t";
    cout << this->getEmail() << "\t";
    cout << this->getAge() <<"\t";
    cout << this->getDays()[0] << ",";
    cout << this->getDays()[1] << ",";
    cout << this->getDays()[2] << "\t";
    cout << degreeTypeStrings[(int) this -> getDegreeProgram()] << "\n";
}

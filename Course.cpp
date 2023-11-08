#include "Course.h"

Course::Course(char cCode[7], string cTitle, int credit, int cap){
    title = cTitle;
    credits = credit;
    enrolled = 0;
    capacity = cap;
    for (int i = 0; i < 8; i++)
        code[i] = cCode[i];

}

Course::Course(const Course& orig){
    title = orig.title;
    credits = orig.credits;;
    enrolled = orig.enrolled;
    capacity = orig.capacity;
    for (int i = 0; i < 8; i++)
        code[i] = orig.code[i];
}

string Course::getCode(){
    return code;
}

string Course::getTitle(){
    return title;
}

int Course::getCapacity(){
    return capacity;
}

int Course::getCredits(){
    return credits;
}

int Course::getEnrolled(){
    return enrolled;
}

bool Course::isFull(){
    return enrolled == capacity;
}

void Course::addStudent(const Student&){
    if(isFull())
        cerr<<"course is full";
    else{
        
    }
}

void Course::dropStudent(const Student&){}

ostream& Course::displayCourse(ostream& out){
    out<<getCode()<<'\t'<<getTitle()<<'\t'<<getCredits()<<'\t'<<getEnrolled()<<'\t'<<getCapacity()<<endl;
    return out;
}

void Course::displayRegisteredStudents(){}

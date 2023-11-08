#include "Course.h"

Course::Course(string cCode, string cTitle, int credit, int cap){
    code = cCode;
    title = cTitle;
    credits = credit;
    enrolled = 0;
    capacity = cap;
}

Course::Course(const Course& orig){
    code = orig.code;
    title = orig.title;
    credits = orig.credits;;
    enrolled = orig.enrolled;
    capacity = orig.capacity;
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
    
}

void Course::displayRegisteredStudents(){}

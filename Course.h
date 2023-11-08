#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
#include "LListWithDummyNode.h"

using namespace std;

class Course{
public:
    Course(string, string, int, int);
    Course(const Course &course);
    string getCode();
    string getTitle();
    int getCapacity();
    int getCredits();
    int getEnrolled();
    void addStudent(const Student&);
    void dropStudent(const Student&);
    bool isFull() const;
    ostream& displayCourse(ostream&) const;
    ostream& displayRegisteredStudents(ostream&) const;
    
private:
    string code;
    string title;
    int credits;
    int enrolled;
    int capacity;
};
#endif /* COURSE_H */

ostream& operator<<(ostream&, Course&);

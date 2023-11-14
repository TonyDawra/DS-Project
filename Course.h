#ifndef COURSE_H
#define COURSE_H

#include "Student.h"
#include <iostream>
#include <istream>
#include <string>
#include <vector>

using namespace std;

class Course {
public:
    Course();

    Course(char*, string, int, int);

    Course(const Course& course);

    void setCode(char[7]);

    void setTitle(string);

    void setCapacity(int);

    void setCredits(int);

    string getCode() const;

    string getTitle() const;

    int getCapacity() const;

    int getCredits() const;

    int getEnrolled() const;

    void addStudent(Student*);

    void dropStudent(Student*);

    bool isFull() const;

    bool operator==(const Course& other);

    ostream& displayCourse(ostream&) const;

    ostream& displayRegisteredStudents(ostream&) const;

private:
    char code[8];
    string title;
    int credits;
    int enrolled;
    int capacity;
    vector<Student*> enrolledStudents;
};

ostream& operator<<(ostream&, Course&);

istream& operator>>(istream&, Course&);

#endif /* COURSE_H */

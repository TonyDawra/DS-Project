#include "Course.h"
#include "Student.h"
#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <iomanip>

Course::Course() {}

Course::Course(char cCode[7], string cTitle, int credit, int cap) {
    title = cTitle;
    credits = credit;
    enrolled = 0;
    capacity = cap;
    for (int i = 0; i < 7; i++)
        code[i] = cCode[i];

    code[7] = '\0';
}

void Course::setCode(char code[7]) {
    for (int i = 0; i < 7; i++) {
        this->code[i] = code[i];
    }
    this->code[7] = '\0';
}

void Course::setCredits(int credits) {
    if (credits < 0) {
        cerr << "Credit amount shouldnt be lower or equal to 0.\n";
        return;
    }

    this->credits = credits;
}

void Course::setTitle(string title) { this->title = title; }

void Course::setCapacity(int capacity) {
    if (capacity < enrolledStudents.size()) {
        cerr << "Can't set capacity to lower than enrolled students.\n";
        return;
    }

    this->capacity = capacity;
}

Course::Course(const Course& orig) {
    title = orig.title;
    credits = orig.credits;

    enrolled = orig.enrolled;
    capacity = orig.capacity;
    for (int i = 0; i < 8; i++)
        code[i] = orig.code[i];
}

bool Course::operator==(const Course& other) {
    for (int i = 0; i < 7; i++) {
        if (other.code[i] != code[i])
            return false;
    }
    return true;
}

string Course::getCode() const { return code; }

string Course::getTitle() const { return title; }

int Course::getCapacity() const { return capacity; }

int Course::getCredits() const { return credits; }

int Course::getEnrolled() const { return enrolledStudents.size(); }

bool Course::isFull() const { return enrolledStudents.size() == capacity; }

void Course::addStudent(Student* student) {
    if (isFull()) {
        cerr << "course is full";
        return;
    }

    student->registercourse(this);
    enrolledStudents.push_back(student);
}

void Course::dropStudent(Student* student) {
    auto toRemove =
        find(enrolledStudents.begin(), enrolledStudents.end(), student);

    if (toRemove == enrolledStudents.end()) {
        cerr << "Student not in course\n";
        return;
    }

    student->dropcourse(this);
    enrolledStudents.erase(toRemove);
}

ostream& Course::displayCourse(ostream& out) const {
    out << getCode() << '\t' << getTitle() << '\'t' << getCredits() << '\t'
        << getEnrolled() << '\t' << getCapacity() << endl;
    return out;
}

ostream& Course::displayRegisteredStudents(ostream& out) const {
    out << "Course: " << getCode() << "-" << getTitle() << endl;
    for (Student* s : enrolledStudents) {
        out << s->getid() << " " << s->getlastname() << ", " << s->getfirstname() << endl;
    }
    return out;
}

istream& operator>>(istream& in, Course& course) {
    char code[8];
    for (int i = 0; i < 7; ++i) {
        in >> code[i];
    }

    code[7] = '\0';
    course.setCode(code);

    string title;
    in >> ws;

    while (!isdigit(in.peek())) {
        title += (char)in.get();
    }

    course.setTitle(title);

    int credits;
    in >> credits;

    course.setCredits(credits);

    int capacity;
    in >> capacity;

    course.setCapacity(capacity);

    return in;
}

ostream& operator<<(ostream& out, Course& course) {
    out << course.getCode() << '\t' << left << setw(25) << course.getTitle() << "\t" << course.getCredits() << "\t\t" << course.getEnrolled()
        << "\t\t" << course.getCapacity();
    return out;
}
